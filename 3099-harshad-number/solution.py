# 3099. Harshad Number
# https://leetcode.com/problems/harshad-number/
# Difficulty: Easy | Language: python3
# Runtime: 0 ms
# Memory: 17.9 MB
# Solved: 2025-04-29

class Solution:
    def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
        a = x
        count = 0
        while a != 0:
            r = a % 10
            count = count + r
            a = a // 10

        if(x % count == 0):
            return count
        else:
            return -1
