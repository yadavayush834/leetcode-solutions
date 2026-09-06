// 78. Subsets
// https://leetcode.com/problems/subsets/
// Difficulty: Medium | Language: cpp
// Runtime: 0 ms
// Memory: 10 MB
// Solved: 2025-10-29

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(); 
        vector<vector<int>>result;
        for(int i = 0 ; i < (1<<n) ; i++){
            vector<int>subset; 
            for(int j = 0 ; j < n ; j++){
                if((i & (1 << j))> 0 ){
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }
        return result; 
        
    }
};
