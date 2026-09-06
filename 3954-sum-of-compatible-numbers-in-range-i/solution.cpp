// 3954. Sum of Compatible Numbers in Range I
// https://leetcode.com/problems/sum-of-compatible-numbers-in-range-i/
// Difficulty: Easy | Language: cpp
// Runtime: 3 ms
// Memory: 8.6 MB
// Solved: 2026-08-04

class Solution {
public:
    long long sumOfGoodIntegers(int n, int k) {

        long long sum = 0;

        int L = max(1, n - k);
        int R = n + k;

        for(int x = L; x <= R; x++) {

            if((n & x) == 0)
                sum += x;

        }

        return sum;
    }
};
