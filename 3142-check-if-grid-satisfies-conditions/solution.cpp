// 3142. Check if Grid Satisfies Conditions
// https://leetcode.com/problems/check-if-grid-satisfies-conditions/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 29.2 MB
// Solved: 2026-09-01

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i + 1 < rows && grid[i][j] != grid[i + 1][j]) {
                    return false;
                }

                if (j + 1 < cols && grid[i][j] == grid[i][j + 1]) {
                    return false;
                }
            }
        }

        return true;
    }
};
