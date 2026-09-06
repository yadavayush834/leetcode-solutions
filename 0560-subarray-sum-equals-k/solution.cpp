// 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/
// Difficulty: Medium | Language: cpp
// Runtime: 43 ms
// Memory: 45.4 MB
// Solved: 2026-08-20

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0] = 1 ; 
        int sum = 0 ; 
        int ans = 0 ; 

        for(int i = 0 ; i< nums.size(); i++){
            sum += nums[i];
            if(mpp.find(sum-k) != mpp.end()){
                ans += mpp[sum-k];
            }
            mpp[sum]++;
        }
        return ans;
    }
};
