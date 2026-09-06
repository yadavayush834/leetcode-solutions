# 541. Reverse String II
# https://leetcode.com/problems/reverse-string-ii/
# Difficulty: Easy | Language: python3
# Runtime: 2 ms
# Memory: 17.8 MB
# Solved: 2025-05-02

class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        n = len(s)
        i = 0
        while i < n:
            # 1) full 2k block or more: reverse first k, keep rest
            if n - i >= 2*k:
                s = s[:i] + s[i:i+k][::-1] + s[i+k:]
            # 2) between k and 2k left: reverse first k, keep rest
            elif n - i >= k:
                s = s[:i] + s[i:i+k][::-1] + s[i+k:]
            # 3) less than k left: reverse all remaining
            else:
                s = s[:i] + s[i:][::-1]
                break
            i += 2*k
        return s
