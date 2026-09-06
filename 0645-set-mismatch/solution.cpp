// 645. Set Mismatch
// https://leetcode.com/problems/set-mismatch/
// Difficulty: Easy | Language: cpp
// Runtime: 25 ms
// Memory: 34.7 MB
// Solved: 2026-08-23

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;

            if (mpp[nums[i]] == 2) {
                ans.push_back(nums[i]);
            }
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (!mpp.contains(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
