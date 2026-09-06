// 598. Range Addition II
// https://leetcode.com/problems/range-addition-ii/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 15.4 MB
// Solved: 2026-04-17

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int x = m, y = n;

        for (auto &v : ops) {
            x = min(x, v[0]);
            y = min(y, v[1]);
        }

        return x * y;
    }
};
