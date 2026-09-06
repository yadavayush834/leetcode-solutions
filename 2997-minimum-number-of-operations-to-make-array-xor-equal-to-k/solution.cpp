// 2997. Minimum Number of Operations to Make Array XOR Equal to K
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/
// Difficulty: Medium | Language: cpp
// Runtime: 101 ms
// Memory: 93 MB
// Solved: 2026-08-13

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xori = 0 ;
        for(int i = 0 ; i< nums.size() ; i++){
            xori ^= nums[i];
        }
        int ans = k ^ xori;
        return __builtin_popcount(ans);
    }
};
