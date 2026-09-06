// 829. Consecutive Numbers Sum
// https://leetcode.com/problems/consecutive-numbers-sum/
// Difficulty: Hard | Language: cpp
// Runtime: 3 ms
// Memory: 7.8 MB
// Solved: 2026-08-03

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;

        for (long long k = 1; k * (k + 1) / 2 <= n; k++) {
            long long rem = n - k * (k - 1) / 2;

            if (rem > 0 && rem % k == 0)
                ans++;
        }

        return ans;
    }
};
