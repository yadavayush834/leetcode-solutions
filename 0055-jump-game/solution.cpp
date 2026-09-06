// 55. Jump Game
// https://leetcode.com/problems/jump-game/
// Difficulty: Medium | Language: cpp
// Runtime: 0 ms
// Memory: 52.3 MB
// Solved: 2025-10-08

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxindex  = 0; 
        for(int i = 0 ; i< nums.size(); i++){
            if(i > maxindex) return false;
            maxindex = max(maxindex, i+nums[i]);
            
        }
        return true;
    }
};
