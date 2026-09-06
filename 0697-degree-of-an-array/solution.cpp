// 697. Degree of an Array
// https://leetcode.com/problems/degree-of-an-array/
// Difficulty: Easy | Language: cpp
// Runtime: 11 ms
// Memory: 30.2 MB
// Solved: 2026-04-17

class Solution {
public:
    int findShortestSubArray(vector<int>& a) {
        unordered_map<int,int> f, l, r;
        int n = a.size(), d = 0;

        for (int i = 0; i < n; i++) {
            if (!l.count(a[i])) l[a[i]] = i;
            r[a[i]] = i;
            f[a[i]]++;
            d = max(d, f[a[i]]);
        }

        int m = n;

        for (auto &p : f) {
            if (p.second == d) {
                m = min(m, r[p.first] - l[p.first] + 1);
            }
        }

        return m;
    }
};
