# 35. Search Insert Position
# https://leetcode.com/problems/search-insert-position/
# Difficulty: Easy | Language: python3
# Runtime: 0 ms
# Memory: 18.3 MB
# Solved: 2025-08-18

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = (left + right) // 2
            
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        
        return left
