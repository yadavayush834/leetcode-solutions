# 169. Majority Element
# https://leetcode.com/problems/majority-element/
# Difficulty: Easy | Language: python3
# Runtime: 8 ms
# Memory: 19.3 MB
# Solved: 2025-04-26

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        hashm = {}

        for i in nums:
            if i in hashm:
                hashm[i] += 1
            else:
                hashm[i] = 1

        for j,k in hashm.items():
            if k > n/2 :
                return j
