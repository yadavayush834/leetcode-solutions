// 976. Largest Perimeter Triangle
// https://leetcode.com/problems/largest-perimeter-triangle/
// Difficulty: Easy | Language: cpp
// Runtime: 9 ms
// Memory: 25.4 MB
// Solved: 2025-08-25

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 3) return 0;

        for (int i = n-1; i >= 2; i--) {
            int c = nums[i];
            int b = nums[i-1];
            int a = nums[i-2];
            if (a + b > c) {
                return a + b + c;
            }
        }
        return 0;
    }
};
