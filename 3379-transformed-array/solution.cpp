// 3379. Transformed Array
// https://leetcode.com/problems/transformed-array/
// Difficulty: Easy | Language: cpp
// Runtime: 8 ms
// Memory: 25.8 MB
// Solved: 2026-02-05

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                ans[i] = nums[i];
            }
            else if (nums[i] > 0) {
                int d = (i + nums[i]) % n;
                ans[i] = nums[d];
            }
            else {
                int d = (i + nums[i]) % n;
                if (d < 0) d += n;
                ans[i] = nums[d];
            }
        }
        return ans;
    }
};
