# 229. Majority Element II
# https://leetcode.com/problems/majority-element-ii/
# Difficulty: Medium | Language: python3
# Runtime: 4 ms
# Memory: 18.9 MB
# Solved: 2025-04-26

class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        n = len(nums)
        hashm = {}
        t = []
        for i in nums:
            if i in hashm:
                hashm[i] += 1
            else:
                hashm[i] = 1

        for j, k in hashm.items():
            if k > n/3:
                t.append(j)

        return t
