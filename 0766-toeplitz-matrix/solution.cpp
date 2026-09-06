// 766. Toeplitz Matrix
// https://leetcode.com/problems/toeplitz-matrix/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 21.1 MB
// Solved: 2026-03-03

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i = 0; i < rows - 1; i++){
            for(int j = 0; j < cols - 1; j++){
                if(matrix[i][j] != matrix[i+1][j+1]){
                    return false;
                }
            }
        }
        return true;
    }
};
