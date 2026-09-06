// 930. Binary Subarrays With Sum
// https://leetcode.com/problems/binary-subarrays-with-sum/
// Difficulty: Medium | Language: cpp
// Runtime: 19 ms
// Memory: 38.7 MB
// Solved: 2026-08-20

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mpp;
        mpp[0] = 1 ;
        int sum = 0 ;
        int ans= 0 ;
        for(int i = 0 ; i< nums.size(); i++){
            sum += nums[i];
            if(mpp.find(sum - goal) != mpp.end()){
                ans += mpp[sum - goal];
            }
            mpp[sum]++;
        }
        return ans; 
    }
};
