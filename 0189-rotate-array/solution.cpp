// 189. Rotate Array
// https://leetcode.com/problems/rotate-array/
// Difficulty: Medium | Language: cpp
// Runtime: 231 ms
// Memory: 29.5 MB
// Solved: 2025-04-06

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return;
        
        k = k % n;
        if(k == 0) {
            for(auto it : nums){
                cout << it << " ";
            }
            return;
        }
        
       
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
       
        reverse(nums.begin() + k, nums.end());
        
     
        for(auto it : nums){
            cout << it << " ";
        }
    }
};
