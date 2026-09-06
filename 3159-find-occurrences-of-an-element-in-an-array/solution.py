# 3159. Find Occurrences of an Element in an Array
# https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/
# Difficulty: Medium | Language: python3
# Runtime: 48 ms
# Memory: 33 MB
# Solved: 2025-04-26

class Solution:
    def occurrencesOfElement(self, nums: List[int], queries: List[int], x: int) -> List[int]:
        answer = []
        hashm = {}
        count = 1
        for idx, val in enumerate(nums):
            if val == x:
                hashm[count] = idx
                count += 1

        for q in queries:
            if q in hashm:
                answer.append(hashm[q])
            else:
                answer.append(-1)
        return answer
