// 152. Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/
// Difficulty: Medium | Language: cpp
// Runtime: 3 ms
// Memory: 17.9 MB
// Solved: 2025-11-07

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1; 
        int suff = 1; 
        int ans = INT_MIN;
        for(int i =0 ; i< nums.size();  i++){
            if(pre == 0) pre = 1;
            if(suff == 0 ) suff = 1 ; 
            pre = pre* nums[i];
            suff = suff * nums[nums.size()-i-1];
            ans  = max(ans,max(pre,suff));
        }
        return ans;
    }
};
