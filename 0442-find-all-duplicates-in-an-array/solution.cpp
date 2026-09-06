// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Difficulty: Medium | Language: cpp
// Runtime: 5 ms
// Memory: 48.4 MB
// Solved: 2025-09-26

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>res; 
        for(int i =0 ; i< nums.size(); i++){
            int index = abs(nums[i]) - 1 ; 
            if(nums[index] < 0){
                res.push_back(index+1);
            }
            else{
                nums[index] = -(nums[index]);
            }
        }
        return res;
        
    }
};
