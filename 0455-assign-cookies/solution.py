# 455. Assign Cookies
# https://leetcode.com/problems/assign-cookies/
# Difficulty: Easy | Language: python3
# Runtime: 23 ms
# Memory: 19.9 MB
# Solved: 2025-04-30

class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:

        g.sort()
        s.sort()
        n1 = len(g)
        n2 = len(s)
        count = 0 
        i = 0 
        j = 0 

        while i < n1 and j < n2:
            if(g[i] <= s[j]):
                count += 1
                j = j+1
                i = i+ 1
            else:
                j = j+1
        return count
