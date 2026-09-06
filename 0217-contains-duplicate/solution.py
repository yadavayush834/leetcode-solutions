# 217. Contains Duplicate
# https://leetcode.com/problems/contains-duplicate/
# Difficulty: Easy | Language: python3
# Runtime: 57 ms
# Memory: 35 MB
# Solved: 2025-04-29

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hashm = {}
        count = 0
        flag = 0 
        for num in nums:
            if num in hashm:
                hashm[num] += 1
            else:
                hashm[num] = 1
        for i, j in hashm.items():
            if j >= 2:
                flag = 1
            
        if(flag):
            return True
        else:
            return False
