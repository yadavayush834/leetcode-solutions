// 287. Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/
// Difficulty: Medium | Language: cpp
// Runtime: 3 ms
// Memory: 65.2 MB
// Solved: 2026-08-21

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int length = nums.size(); 
        for(int i = 0 ; i< nums.size(); i++){
            
            int t = abs(nums[i]);
            if(nums[t] < 0){
                return t;
            }
            nums[t] = - nums[t];
        }
        return length; 
    }
};
