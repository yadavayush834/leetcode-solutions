# 1720. Decode XORed Array
# https://leetcode.com/problems/decode-xored-array/
# Difficulty: Easy | Language: python3
# Runtime: 3 ms
# Memory: 19.6 MB
# Solved: 2025-04-29

class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        L = []
        L.append(first)
        a = first ^ encoded[0]
        L.append(a)
        for i in range(1,len(encoded)):
            x = 0
            x = L[i] ^ encoded[i]
            L.append(x)

        return L
