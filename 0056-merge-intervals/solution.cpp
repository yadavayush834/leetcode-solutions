// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/
// Difficulty: Medium | Language: cpp
// Runtime: 8 ms
// Memory: 24.9 MB
// Solved: 2026-08-12

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        vector<vector<int>> merged;

        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {

            vector<int> a = intervals[i];

       
            if (a[0] <= prev[1]) {
                prev[0] = min(a[0], prev[0]);
                prev[1] = max(a[1], prev[1]);
            }

          
            else {
                merged.push_back(prev);
                prev = a;
            }
        }

        
        merged.push_back(prev);

        return merged;
    }
};
