// 3731. Find Missing Elements
// https://leetcode.com/problems/find-missing-elements/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 33.9 MB
// Solved: 2026-08-26

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        map<int, int> mpp;

        for (auto it : nums) {
            mpp[it]++;
        }

        int mini = mpp.begin()->first;
        int maxi = mpp.rbegin()->first;

        vector<int> ans;

        for (int i = mini; i <= maxi; i++) {
            if (!mpp.contains(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
