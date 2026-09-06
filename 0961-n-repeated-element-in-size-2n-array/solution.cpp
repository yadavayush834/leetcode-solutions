// 961. N-Repeated Element in Size 2N Array
// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
// Difficulty: Easy | Language: cpp
// Runtime: 17 ms
// Memory: 34.1 MB
// Solved: 2025-10-04

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i = 0 ; i< nums.size(); i++){
            mpp[nums[i]]++;
        }
        int n = mpp.size()-1;
        int ans = 0 ;
        for(auto &entry : mpp){
            if(entry.second == n){
                ans = entry.first;
            }
        }
        return ans; 
    }
};
