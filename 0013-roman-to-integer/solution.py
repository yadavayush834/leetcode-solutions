# 13. Roman to Integer
# https://leetcode.com/problems/roman-to-integer/
# Difficulty: Easy | Language: python3
# Runtime: 4 ms
# Memory: 17.8 MB
# Solved: 2025-03-30

class Solution:
    def romanToInt(self, s: str) -> int:
        mpp = {
            'I': 1, 'V': 5, 'X': 10, 'L': 50,
            'C': 100, 'D': 500, 'M': 1000
        }

        total = 0
        n = len(s)
        i = 0 

        while i < n:
            if i < n - 1 and mpp[s[i]] < mpp[s[i + 1]]:
                total += mpp[s[i + 1]] - mpp[s[i]]  
                i += 2  
            else:
                total += mpp[s[i]]  
                i += 1

        return total
