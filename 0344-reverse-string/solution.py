# 344. Reverse String
# https://leetcode.com/problems/reverse-string/
# Difficulty: Easy | Language: python3
# Runtime: 7 ms
# Memory: 22.9 MB
# Solved: 2025-05-02

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        for i in range(0,len(s)//2):
            s[(len(s)-1)-i],s[i] = s[i], s[(len(s)-1)-i]
