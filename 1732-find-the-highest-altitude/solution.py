# 1732. Find the Highest Altitude
# https://leetcode.com/problems/find-the-highest-altitude/
# Difficulty: Easy | Language: python3
# Runtime: 0 ms
# Memory: 17.9 MB
# Solved: 2025-04-29

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        first = 0 
        second = gain[0]
        maxi = max(first,second)
        for i in range(1,len(gain)):
            third = second + gain[i]
            maxi = max(third,maxi)
            second = third

        return maxi
