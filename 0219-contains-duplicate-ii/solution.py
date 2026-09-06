# 219. Contains Duplicate II
# https://leetcode.com/problems/contains-duplicate-ii/
# Difficulty: Easy | Language: python3
# Runtime: 29 ms
# Memory: 36.7 MB
# Solved: 2025-04-29

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hashm = {}
        flag = 0
        for i,num in enumerate(nums):
            if num in hashm and i - hashm[num] <= k:
                return True
            hashm[num] = i 
        return False
