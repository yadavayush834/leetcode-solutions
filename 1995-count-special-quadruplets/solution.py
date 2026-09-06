# 1995. Count Special Quadruplets
# https://leetcode.com/problems/count-special-quadruplets/
# Difficulty: Easy | Language: python3
# Runtime: 572 ms
# Memory: 17.9 MB
# Solved: 2025-05-02

class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
        count = 0
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                for k in range(j+1,len(nums)):
                    for d in range(k+1,len(nums)):
                        if(nums[i]+nums[j]+nums[k] == nums[d]):
                            count += 1        


        return count
