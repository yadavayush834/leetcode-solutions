// 1991. Find the Middle Index in Array
// https://leetcode.com/problems/find-the-middle-index-in-array/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 16 MB
// Solved: 2026-04-17

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;

        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (left == total - left - nums[i]) {
                return i;
            }
            left += nums[i];
    }
    return -1;
    }
};
