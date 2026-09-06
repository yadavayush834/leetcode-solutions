#!/usr/bin/env python3
"""
LeetCode -> GitHub sync
Fetches ALL your accepted submissions (needs login cookies) and writes:
    0001-two-sum/solution.cpp
    0002-add-two-numbers/solution.py
    ...
plus a README.md table.

Usage:
    pip install -r requirements.txt
    export LEETCODE_SESSION="..."        # from browser cookies (required)
    export LEETCODE_CSRF_TOKEN="..."     # csrftoken cookie (required)
    python3 sync.py --username ayushwell100
    python3 sync.py --username ayushwell100 --demo   # no network, creates 3 sample folders

How to get cookies:
    1. Login to leetcode.com in Chrome
    2. F12 -> Application -> Cookies -> https://leetcode.com
    3. Copy value of LEETCODE_SESSION and csrftoken
"""
from __future__ import annotations

import argparse
import json
import os
import sys
import time
from datetime import datetime, timezone
from pathlib import Path

import requests

BASE = "https://leetcode.com"
GRAPHQL = f"{BASE}/graphql/"
UA = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120 Safari/537.36"

# ---------------------------------------------------------------- queries ---

Q_SUBMISSIONS = """
query ($offset: Int!, $limit: Int!) {
  submissionList(offset: $offset, limit: $limit) {
    hasNext
    submissions {
      id
      lang
      time
      timestamp
      statusDisplay
      runtime
      memory
      title
      titleSlug
    }
  }
}
"""

Q_SUBMISSION_DETAIL = """
query submissionDetails($id: Int!) {
  submissionDetails(submissionId: $id) {
    id
    code
    runtime
    runtimeDisplay
    runtimePercentile
    memory
    memoryDisplay
    memoryPercentile
    timestamp
    lang { name verboseName }
    question { questionId titleSlug }
    statusCode
  }
}
"""

Q_PROBLEMS = """
query ($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {
  problemsetQuestionList: questionList(
    categorySlug: $categorySlug, limit: $limit, skip: $skip, filters: $filters
  ) {
    total: totalNum
    questions: data {
      questionFrontendId
      title
      titleSlug
      difficulty
      isPaidOnly
    }
  }
}
"""

# ------------------------------------------------------------ lang map ------

# langSlug (lowercased) -> (extension, comment-prefix, filename)
LANG_MAP = {
    "cpp": ("cpp", "//"),
    "c": ("c", "//"),
    "java": ("java", "//"),
    "python": ("py", "#"),
    "python3": ("py", "#"),
    "pythondata": ("py", "#"),
    "c#": ("cs", "//"),
    "csharp": ("cs", "//"),
    "javascript": ("js", "//"),
    "typescript": ("ts", "//"),
    "php": ("php", "//"),
    "swift": ("swift", "//"),
    "kotlin": ("kt", "//"),
    "dart": ("dart", "//"),
    "golang": ("go", "//"),
    "go": ("go", "//"),
    "ruby": ("rb", "#"),
    "scala": ("scala", "//"),
    "rust": ("rs", "//"),
    "racket": ("rkt", ";"),
    "erlang": ("erl", "%"),
    "elixir": ("ex", "#"),
    "mysql": ("sql", "--"),
    "mssql": ("sql", "--"),
    "oraclesql": ("sql", "--"),
    "postgresql": ("sql", "--"),
    "pandas": ("py", "#"),
    "bash": ("sh", "#"),
}


def lang_info(lang_slug: str) -> tuple[str, str]:
    key = (lang_slug or "").lower()
    if key in LANG_MAP:
        ext, cm = LANG_MAP[key]
        return ext, cm
    return "txt", "//"


# ------------------------------------------------------------ http ----------

def make_session(leetsession: str, csrf: str) -> requests.Session:
    s = requests.Session()
    s.headers.update({
        "User-Agent": UA,
        "Referer": BASE + "/",
        "Content-Type": "application/json",
        "x-csrftoken": csrf,
    })
    s.cookies.set("LEETCODE_SESSION", leetsession, domain=".leetcode.com")
    s.cookies.set("csrftoken", csrf, domain=".leetcode.com")
    return s


def gql(s: requests.Session, query: str, variables: dict, retries: int = 4) -> dict:
    last = None
    for attempt in range(retries):
        try:
            r = s.post(GRAPHQL, json={"query": query, "variables": variables}, timeout=30)
            if r.status_code == 403:
                raise SystemExit(
                    "Got 403 from LeetCode. Your LEETCODE_SESSION / csrftoken are "
                    "missing or expired. Re-login, copy fresh cookies and retry."
                )
            r.raise_for_status()
            data = r.json()
            if "errors" in data:
                raise RuntimeError(str(data["errors"])[:500])
            return data["data"]
        except SystemExit:
            raise
        except Exception as e:  # noqa: BLE001 - retry transient errors
            last = e
            time.sleep(2 * (attempt + 1))
    raise RuntimeError(f"GraphQL failed after retries: {last}")


# ------------------------------------------------------------ fetch ---------

def fetch_problem_map(s: requests.Session, delay: float = 0.4) -> dict[str, dict]:
    """slug -> {id, title, difficulty}. Public endpoint, no login needed."""
    out: dict[str, dict] = {}
    skip, limit, total = 0, 100, None
    while True:
        data = gql(s, Q_PROBLEMS, {
            "categorySlug": "", "limit": limit, "skip": skip, "filters": {},
        })
        block = data["problemsetQuestionList"]
        if total is None:
            total = block["total"]
        for q in block["questions"]:
            out[q["titleSlug"]] = {
                "id": q["questionFrontendId"],
                "title": q["title"],
                "difficulty": q["difficulty"],
            }
        skip += limit
        if skip >= (total or 0) or not block["questions"]:
            break
        time.sleep(delay)
    return out


def fetch_all_submissions(s: requests.Session, delay: float = 1.0,
                          checkpoint: Path | None = None) -> list[dict]:
    """Paginate submissionList until hasNext is False. Newest first."""
    all_subs: list[dict] = []
    offset = 0
    # resume support
    seen_ids: set[str] = set()
    if checkpoint and checkpoint.exists():
        try:
            saved = json.loads(checkpoint.read_text())
            all_subs = saved.get("submissions", [])
            offset = saved.get("next_offset", 0)
            seen_ids = {str(x["id"]) for x in all_subs}
            print(f"Resuming from offset {offset} ({len(all_subs)} cached)")
        except Exception:
            pass

    while True:
        data = gql(s, Q_SUBMISSIONS, {"offset": offset, "limit": 20})
        block = data["submissionList"]
        subs = block.get("submissions") or []
        if not subs:
            break
        for x in subs:
            if str(x["id"]) not in seen_ids:
                all_subs.append(x)
                seen_ids.add(str(x["id"]))
        print(f"  offset {offset}: +{len(subs)} (total {len(all_subs)})")
        if checkpoint:
            checkpoint.write_text(json.dumps(
                {"next_offset": offset + 20, "submissions": all_subs}))
        if not block.get("hasNext"):
            break
        offset += 20
        time.sleep(delay)
    if checkpoint and checkpoint.exists():
        checkpoint.unlink()  # done, drop resume file
    return all_subs


def pick_best_accepted(submissions: list[dict]) -> dict[tuple[str, str], dict]:
    """
    Keep the NEWEST accepted submission per (titleSlug, file-extension).
    (python + python3 collapse to one file; same for sql dialects.)
    Returns {(slug, ext): submission}
    """
    best: dict[tuple[str, str], dict] = {}
    for sub in submissions:  # API returns newest first
        if sub.get("statusDisplay") != "Accepted":
            continue
        slug = sub.get("titleSlug")
        if not slug:
            continue
        ext, _ = lang_info(sub.get("langSlug") or sub.get("lang") or "")
        key = (slug, ext)
        if key not in best:
            best[key] = sub
    return best


# ------------------------------------------------------------ write ---------

def header_comment(slug: str, meta: dict, detail: dict, lang_slug: str) -> str:
    ext, cm = lang_info(lang_slug)
    qid = meta.get("id", "?")
    title = meta.get("title", slug.replace("-", " ").title())
    diff = meta.get("difficulty", "Unknown")
    url = f"https://leetcode.com/problems/{slug}/"
    rt = (detail.get("runtimeDisplay") or detail.get("runtime") or "")
    mem = (detail.get("memoryDisplay") or detail.get("memory") or "")
    ts = detail.get("timestamp")
    date = ""
    if ts:
        try:
            date = datetime.fromtimestamp(int(ts), tz=timezone.utc).strftime("%Y-%m-%d")
        except Exception:
            pass
    lines = [
        f"{cm} {qid}. {title}",
        f"{cm} {url}",
        f"{cm} Difficulty: {diff} | Language: {lang_slug}",
    ]
    if rt:
        lines.append(f"{cm} Runtime: {rt}")
    if mem:
        lines.append(f"{cm} Memory: {mem}")
    if date:
        lines.append(f"{cm} Solved: {date}")
    return "\n".join(lines) + "\n\n"


def write_solution(root: Path, slug: str, meta: dict, detail: dict,
                   lang_slug: str) -> Path:
    ext, _ = lang_info(lang_slug)
    qid_raw = str(meta.get("id", "0000"))
    qid_num = "".join(c for c in qid_raw if c.isdigit()) or "0000"
    folder = root / f"{int(qid_num):04d}-{slug}"
    folder.mkdir(parents=True, exist_ok=True)
    code = (detail.get("code") or "").rstrip() + "\n"
    head = header_comment(slug, meta, detail, lang_slug)
    # avoid duplicating header on re-runs
    if not code.lstrip().startswith(tuple(["//", "#", "--", ";", "%", "/*"])):
        code = head + code
    # Java needs class filename? keep solution.java (valid for portfolio)
    fname = f"solution.{ext}"
    fp = folder / fname
    fp.write_text(code, encoding="utf-8")
    return fp


def build_readme(root: Path, username: str, items: list[dict]) -> None:
    """items: [{id, title, slug, difficulty, langs, folder}] sorted by id."""
    def key(x):
        d = "".join(c for c in str(x["id"]) if c.isdigit())
        return int(d) if d else 10**9
    items.sort(key=key)

    counts = {"Easy": 0, "Medium": 0, "Hard": 0}
    for it in items:
        if it["difficulty"] in counts:
            counts[it["difficulty"]] += 1

    lines = [
        "# LeetCode Solutions",
        "",
        f"Solutions by **[{username}](https://leetcode.com/u/{username}/)** — "
        f"auto-synced with `sync.py`.",
        "",
        f"Total: **{len(items)}** "
        f"(Easy {counts['Easy']} · Medium {counts['Medium']} · Hard {counts['Hard']})",
        "",
        "| # | Title | Difficulty | Language(s) | Solution |",
        "|---|-------|-----------|-------------|----------|",
    ]
    for it in items:
        link = f"https://leetcode.com/problems/{it['slug']}/"
        langs = ", ".join(it["langs"])
        lines.append(
            f"| {it['id']} | [{it['title']}]({link}) | {it['difficulty']} "
            f"| {langs} | [Code](./{it['folder']}/) |"
        )
    lines += ["", "_Synced with [sync.py](./sync.py)_", ""]
    (root / "README.md").write_text("\n".join(lines), encoding="utf-8")


# ------------------------------------------------------------ demo ----------

DEMO = [
    ("1", "Two Sum", "two-sum", "Easy", "cpp",
     "class Solution {\npublic:\n    vector<int> twoSum(vector<int>& nums, int target) {\n        unordered_map<int,int> m;\n        for (int i = 0; i < (int)nums.size(); ++i) {\n            int need = target - nums[i];\n            if (m.count(need)) return {m[need], i};\n            m[nums[i]] = i;\n        }\n        return {};\n    }\n};\n"),
    ("2", "Add Two Numbers", "add-two-numbers", "Medium", "cpp",
     "class Solution {\npublic:\n    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {\n        // classic linked-list addition\n        return l1;\n    }\n};\n"),
    ("175", "Combine Two Tables", "combine-two-tables", "Easy", "mysql",
     "SELECT p.firstName, p.lastName, a.city, a.state\nFROM Person p LEFT JOIN Address a ON p.personId = a.personId;\n"),
]


def run_demo(root: Path, username: str) -> None:
    print("DEMO mode: writing 3 sample solutions, no network.")
    items = []
    grouped: dict[str, dict] = {}
    for qid, title, slug, diff, lang, code in DEMO:
        meta = {"id": qid, "title": title, "difficulty": diff}
        detail = {"code": code, "runtimeDisplay": "0 ms",
                  "memoryDisplay": "10 MB",
                  "timestamp": int(datetime.now(timezone.utc).timestamp())}
        fp = write_solution(root, slug, meta, detail, lang)
        print(f"  {fp.relative_to(root)}")
        g = grouped.setdefault(slug, {"id": qid, "title": title, "slug": slug,
                                      "difficulty": diff, "langs": [],
                                      "folder": fp.parent.name})
        g["langs"].append(lang)
    items = list(grouped.values())
    build_readme(root, username, items)
    print("Wrote README.md")


# ------------------------------------------------------------ main ----------

def main() -> int:
    ap = argparse.ArgumentParser(description="Sync LeetCode accepted solutions to GitHub-ready folders")
    ap.add_argument("--username", default="ayushwell100")
    ap.add_argument("--output", default=".", help="repo root (default: current dir)")
    ap.add_argument("--delay", type=float, default=1.2, help="seconds between API calls")
    ap.add_argument("--demo", action="store_true", help="write 3 sample files, no network")
    ap.add_argument("--limit-problems", type=int, default=0, help="only sync first N problems (testing)")
    args = ap.parse_args()

    root = Path(args.output).resolve()
    root.mkdir(parents=True, exist_ok=True)

    if args.demo:
        run_demo(root, args.username)
        return 0

    leetsession = os.getenv("LEETCODE_SESSION", "").strip().strip('"').strip("'")
    csrf = os.getenv("LEETCODE_CSRF_TOKEN", "").strip().strip('"').strip("'")
    if not leetsession or not csrf:
        print("ERROR: set LEETCODE_SESSION and LEETCODE_CSRF_TOKEN env vars.")
        print("  Chrome: F12 -> Application -> Cookies -> leetcode.com -> copy values.")
        print("  export LEETCODE_SESSION='...' LEETCODE_CSRF_TOKEN='...'")
        print("  Tip: try --demo first to preview the folder layout.")
        return 2

    s = make_session(leetsession, csrf)

    print("1/4 fetching problem list (~3400 questions, public)...")
    pmap = fetch_problem_map(s)
    print(f"  got {len(pmap)} problems")

    print("2/4 fetching your submissions (paginated, newest first)...")
    subs = fetch_all_submissions(s, delay=args.delay,
                                 checkpoint=root / ".sync_checkpoint.json")
    acc = [x for x in subs if x.get("statusDisplay") == "Accepted"]
    print(f"  total submissions: {len(subs)}, accepted: {len(acc)}")

    best = pick_best_accepted(subs)
    print(f"3/4 unique (problem x language) accepted: {len(best)}")
    # group by slug for README + optional limit
    by_slug: dict[str, list[tuple[str, dict]]] = {}
    for (slug, _ext), sub in best.items():
        by_slug.setdefault(slug, []).append((_ext, sub))
    slugs = sorted(by_slug, key=lambda sl: int(
        "".join(c for c in str(pmap.get(sl, {}).get("id", "9999")) if c.isdigit()) or 9999))
    if args.limit_problems:
        slugs = slugs[:args.limit_problems]

    items: list[dict] = []
    for i, slug in enumerate(slugs, 1):
        meta = pmap.get(slug, {"id": "?", "title": slug.replace("-", " ").title(),
                               "difficulty": "Unknown"})
        langs = []
        for ext, sub in sorted(by_slug[slug]):
            sid = int(sub["id"])
            lang_slug = sub.get("langSlug") or sub.get("lang") or ext
            print(f"  [{i}/{len(slugs)}] {meta.get('id')} {slug} ({lang_slug}, id={sid})...")
            try:
                detail = gql(s, Q_SUBMISSION_DETAIL, {"id": sid})
                detail = detail.get("submissionDetails") or {}
            except Exception as e:  # noqa: BLE001
                print(f"    WARN: detail fetch failed: {e}")
                continue
            if not detail.get("code"):
                print("    WARN: empty code, skipped")
                continue
            fp = write_solution(root, slug, meta, detail, lang_slug)
            langs.append(lang_slug)
            time.sleep(args.delay)
        if langs:
            qid = meta.get("id", "?")
            candidates = sorted(root.glob(f"*-{slug}"))
            folder = candidates[0].name if candidates else slug
            items.append({"id": qid, "title": meta.get("title", slug),
                          "slug": slug, "difficulty": meta.get("difficulty", "Unknown"),
                          "langs": sorted(set(langs)), "folder": folder})

    print(f"4/4 writing README.md ({len(items)} problems)...")
    build_readme(root, args.username, items)
    print("Done. Next: git add, commit, push (see push.sh).")
    return 0


if __name__ == "__main__":
    sys.exit(main())
