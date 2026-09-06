// 3702. Longest Subsequence With Non-Zero Bitwise XOR
// https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/
// Difficulty: Medium | Language: cpp
// Runtime: 0 ms
// Memory: 171.2 MB
// Solved: 2026-08-15

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = nums[0];
        bool n = false;
        for(int i =1; i< nums.size(); i++){
            
            ans = ans ^ nums[i];
            if(nums[i] != 0){
                n = true;
            }
        }
        if(ans != 0){
            return nums.size();
        }
        else if(ans == 0 && n == 1){
            return nums.size()-1; 
        }
        else{
            return 0 ; 
        }
        
    }
};
