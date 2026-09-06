// 628. Maximum Product of Three Numbers
// https://leetcode.com/problems/maximum-product-of-three-numbers/
// Difficulty: Easy | Language: cpp
// Runtime: 7 ms
// Memory: 31.7 MB
// Solved: 2026-08-23

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        return max(
            nums[0] * nums[1] * nums[n - 1],
            nums[n - 3] * nums[n - 2] * nums[n - 1]
        );
    }
};
