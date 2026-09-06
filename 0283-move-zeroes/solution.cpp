// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 23.8 MB
// Solved: 2025-08-25

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;
      
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[write++] = nums[i];
            }
        }
       
        while (write < nums.size()) {
            nums[write++] = 0;
        }
    }
};
