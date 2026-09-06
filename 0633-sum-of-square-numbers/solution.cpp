// 633. Sum of Square Numbers
// https://leetcode.com/problems/sum-of-square-numbers/
// Difficulty: Medium | Language: cpp
// Runtime: 0 ms
// Memory: 7.8 MB
// Solved: 2026-08-02

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0;
        long long b = sqrt(c);

        while (a <= b) {
            long long sum = a * a + b * b;

            if (sum == c)
                return true;
            else if (sum < c)
                a++;
            else
                b--;
        }

        return false;
    }
};
