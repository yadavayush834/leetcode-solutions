# 9. Palindrome Number
# https://leetcode.com/problems/palindrome-number/
# Difficulty: Easy | Language: python3
# Runtime: 8 ms
# Memory: 17.6 MB
# Solved: 2025-04-29

class Solution:
    def isPalindrome(self, x: int) -> bool:
        a = str(x)

        if(x < 0):
            return False
        else:
            if a == a[::-1]:
                return True
            else:
                return False
