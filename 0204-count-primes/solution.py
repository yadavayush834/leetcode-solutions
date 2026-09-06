# 204. Count Primes
# https://leetcode.com/problems/count-primes/
# Difficulty: Medium | Language: python3
# Runtime: 1205 ms
# Memory: 56.4 MB
# Solved: 2025-08-18

class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0 
        array = [True]*(n)
        array[0] = array[1] = False

        for i in range(2, int(math.sqrt(n))+1):
            if array[i]:
                for j in range(i*i,n,i):
                    array[j] = False
        return sum(array)
