// 268. Missing Number
// https://leetcode.com/problems/missing-number/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 21.8 MB
// Solved: 2025-08-20

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        
        for (int i = 0; i < nums.size(); i++) {
            res += i - nums[i];
        }
        
        return res;   
        
    }
};
