// 136. Single Number
// https://leetcode.com/problems/single-number/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 20.5 MB
// Solved: 2025-08-25

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xori = 0 ;
        for(int i = 0 ; i< nums.size(); i++){
            xori ^= nums[i];
        }
        return xori;
        
    }
};
