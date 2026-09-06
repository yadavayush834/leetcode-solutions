# 2433. Find The Original Array of Prefix Xor
# https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
# Difficulty: Medium | Language: python3
# Runtime: 30 ms
# Memory: 36 MB
# Solved: 2025-04-29

class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        L = []
        L.append(pref[0])
        for i in range(1,len(pref)):
            a = pref[i-1] ^ pref[i]
            L.append(a)

        return L
