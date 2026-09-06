// 50. Pow(x, n)
// https://leetcode.com/problems/powx-n/
// Difficulty: Medium | Language: cpp
// Runtime: 0 ms
// Memory: 8.8 MB
// Solved: 2026-08-02

class Solution {
public:
    double myPow(double x, int n) {

        long long N = n;
        double ans = 1.0;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        while (N > 0) {
            if (N % 2 == 1)
                ans *= x;

            x *= x;
            N /= 2;
        }

        return ans;
    }
};
