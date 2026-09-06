# 1534. Count Good Triplets
# https://leetcode.com/problems/count-good-triplets/
# Difficulty: Easy | Language: python3
# Runtime: 1348 ms
# Memory: 18 MB
# Solved: 2025-05-02

from collections import Counter

class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        count = 0
        n = len(arr)

        for i in range(n):
            for j in range(i + 1, n):
                if abs(arr[i] - arr[j]) <= a:
                    # Build a frequency map for arr[k] where k > j
                    freq = Counter(arr[j + 1:])
                    
                    low = max(arr[i] - c, arr[j] - b)
                    high = min(arr[i] + c, arr[j] + b)

                    # Count valid arr[k]s in range [low, high]
                    for val in range(low, high + 1):
                        count += freq[val]

        return count
