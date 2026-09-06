// 2545. Sort the Students by Their Kth Score
// https://leetcode.com/problems/sort-the-students-by-their-kth-score/
// Difficulty: Medium | Language: cpp
// Runtime: 0 ms
// Memory: 32.1 MB
// Solved: 2026-08-13

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {

        sort(score.begin(), score.end(), [k](vector<int>& a, vector<int>& b) {
            return a[k] > b[k];
        });

        return score;
    }
};
