# 53. Maximum Subarray
# https://leetcode.com/problems/maximum-subarray/
# Difficulty: Medium | Language: python3
# Runtime: 22 ms
# Memory: 32 MB
# Solved: 2025-04-29

import sys
class Solution:

    def maxSubArray(self, nums: List[int]) -> int:
        INT_MIN = -sys.maxsize - 1
        sumi = 0
        maxi= INT_MIN
        for i in range(len(nums)):
            sumi = sumi + nums[i]

            if(sumi >maxi):
                maxi = sumi

            if(sumi < 0):
                sumi = 0 

        return maxi
