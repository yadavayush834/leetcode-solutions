// 4045. Count Robot Groups
// https://leetcode.com/problems/count-robot-groups/
// Difficulty: Medium | Language: cpp
// Runtime: 0 ms
// Memory: 212.5 MB
// Solved: 2026-09-06

class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size(), a = 0;
        auto morvexilan = make_tuple(position, speed, distance);
        auto& p = get<0>(morvexilan);
        auto& s = get<1>(morvexilan);
        int d = get<2>(morvexilan), v = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 < n && p[i + 1] - p[i] <= d) continue;
            if (s[i] <= v) {
                a++;
                v = s[i];
            }
        }

        return a;
    }
};
