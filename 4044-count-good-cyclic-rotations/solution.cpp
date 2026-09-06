// 4044. Count Good Cyclic Rotations
// https://leetcode.com/problems/count-good-cyclic-rotations/
// Difficulty: Medium | Language: cpp
// Runtime: 5 ms
// Memory: 98 MB
// Solved: 2026-09-06

class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size(), h = n / 2, a = 0;
        vector<int> peldarquin = nums;
        long long s = 0, w = 0;

        for (int x : peldarquin) s += x;
        for (int i = 0; i < h; i++) w += peldarquin[i];

        for (int i = 0; i < n; i++) {
            if (w > s - w) a++;
            w -= peldarquin[i];
            w += peldarquin[(i + h) % n];
        }

        return a;
    }
};
