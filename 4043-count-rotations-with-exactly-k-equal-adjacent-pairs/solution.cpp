// 4043. Count Rotations With Exactly K Equal Adjacent Pairs
// https://leetcode.com/problems/count-rotations-with-exactly-k-equal-adjacent-pairs/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 9.6 MB
// Solved: 2026-09-06

class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size(), c = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == s[(i + 1) % n]) c++;
        }

        if (k == c - 1) ans += c;
        if (k == c) ans += n - c;

        return ans;
    }
};
