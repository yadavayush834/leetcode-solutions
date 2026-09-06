#!/usr/bin/env bash
# Push solutions to GitHub. Usage: ./push.sh [repo-url]
# Example: ./push.sh git@github.com:ayushwell100/leetcode-solutions.git
set -eu
cd "$(dirname "$0")"

if [ ! -d .git ]; then
  git init -b main
fi

git add -A
if git diff --cached --quiet; then
  echo "Nothing to commit."
else
  COUNT=$(ls -d [0-9]*-* 2>/dev/null | wc -l | tr -d ' ')
  git commit -m "sync: ${COUNT} LeetCode solutions"
fi

if [ $# -ge 1 ]; then
  git remote remove origin 2>/dev/null || true
  git remote add origin "$1"
  git push -u origin main
else
  echo "Committed locally. To push: ./push.sh <your-repo-url>"
  echo "Or: gh repo create leetcode-solutions --public --source=. --push"
fi
