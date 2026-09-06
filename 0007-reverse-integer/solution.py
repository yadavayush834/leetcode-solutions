# 7. Reverse Integer
# https://leetcode.com/problems/reverse-integer/
# Difficulty: Medium | Language: python3
# Runtime: 32 ms
# Memory: 17.7 MB
# Solved: 2025-04-29

class Solution:
    def reverse(self, x: int) -> int:
        a = x
        
        INT_MIN = -2**31
        INT_MAX = 2**31 - 1

        sign = 1

        if(x < 0):
            sign = -1
            x = abs(x)
            a = x
        rev = 0
        
         

        while(a!=0):
            r = a % 10
            if rev > INT_MAX // 10 or (rev == INT_MAX // 10 and r >
            INT_MAX % 10):
                return 0
            rev = rev * 10 + r
            a = a // 10
            
        rev = rev * sign

        if rev< INT_MIN or rev > INT_MAX:
            return 0


        return rev
