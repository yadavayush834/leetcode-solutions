// 713. Subarray Product Less Than K
// https://leetcode.com/problems/subarray-product-less-than-k/
// Difficulty: Medium | Language: cpp
// Runtime: 0 ms
// Memory: 65.3 MB
// Solved: 2025-11-07

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; 
        int product = 1; 
        int left = 0; 
        int count = 0 ; 
        for(int right = 0 ; right< nums.size(); right++){
            product *= nums[right];
            while(product >= k && left<= right){
                product /= nums[left];
                left++;
            }
            count += right-left+1; 


            
            
        }
        return count;
    }
};
