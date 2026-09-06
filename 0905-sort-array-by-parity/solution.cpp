// 905. Sort Array By Parity
// https://leetcode.com/problems/sort-array-by-parity/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 20.4 MB
// Solved: 2025-08-25

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0 ;
        int left = 0 ;
        for(int i =0 ; i< nums.size() ; i++){
            if(nums[i] %2 == 0){
                swap(nums[left],nums[i]);
                left++;
            }
        }
        return nums;
    }
};
