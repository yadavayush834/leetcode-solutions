// 724. Find Pivot Index
// https://leetcode.com/problems/find-pivot-index/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 35.8 MB
// Solved: 2026-04-17

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int x : nums) totalSum += x;

        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
