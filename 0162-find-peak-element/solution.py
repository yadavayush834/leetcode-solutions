# 162. Find Peak Element
# https://leetcode.com/problems/find-peak-element/
# Difficulty: Medium | Language: python3
# Runtime: 0 ms
# Memory: 17.6 MB
# Solved: 2025-04-29

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0
        if nums[0] > nums[1]:
            return 0
        if nums[n-1] > nums[n-2]:
            return n-1
        left = 0 
        right = n -1
        while(left < right):
            mid = left + (right - left) // 2
            if(nums[mid] > nums[mid -1] and nums[mid] > nums[mid +1]):
                return mid
            elif nums[mid -1] > nums[mid]:
                right = mid
            else:
                left = mid
