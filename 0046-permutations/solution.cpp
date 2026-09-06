// 46. Permutations
// https://leetcode.com/problems/permutations/
// Difficulty: Medium | Language: cpp
// Runtime: 3 ms
// Memory: 13.3 MB
// Solved: 2025-09-26

class Solution {
public:
    vector<vector<int>>res;
    void backtrack(vector<int>nums,vector<int>used,vector<int>path){
        if(path.size() == nums.size()){
            res.push_back(path);
            return; 
        }
        for(int i =0 ; i< nums.size() ; i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums,used,path);

            path.pop_back();
            used[i] = false;

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>path;
        vector<int>used(nums.size(),false);
        backtrack(nums,used,path);
        return res;
        
    }
};
