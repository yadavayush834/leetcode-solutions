// 611. Valid Triangle Number
// https://leetcode.com/problems/valid-triangle-number/
// Difficulty: Medium | Language: cpp
// Runtime: 35 ms
// Memory: 16.6 MB
// Solved: 2026-08-02

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = 0;

        for (int k = n - 1; k >= 2; k--) {
            int i = 0;
            int j = k - 1;

            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    ans += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }

        return ans;
    }
};
