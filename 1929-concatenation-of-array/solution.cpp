// 1929. Concatenation of Array
// https://leetcode.com/problems/concatenation-of-array/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 17.1 MB
// Solved: 2025-08-27

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans;
        for(int i =0 ; i < nums.size(); i++){
            ans.push_back(nums[i]);
        }
        for(int i =0 ; i< nums.size();i++){
            ans.push_back(nums[i]);
        }
        return ans;

        
    }
};
