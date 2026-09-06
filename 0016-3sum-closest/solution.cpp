// 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/
// Difficulty: Medium | Language: cpp
// Runtime: 12 ms
// Memory: 13.9 MB
// Solved: 2025-08-31

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];
                int diff = abs(target - total);

                if (diff < mini) {
                    mini = diff;
                    ans = total;
                }

                if (total < target) {
                    j++; 
                } else if (total > target) {
                    k--;  
                } else {
                    return total;  
                }
            }
        }
        return ans;
    }
};
