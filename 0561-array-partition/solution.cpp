// 561. Array Partition
// https://leetcode.com/problems/array-partition/
// Difficulty: Easy | Language: cpp
// Runtime: 9 ms
// Memory: 32.2 MB
// Solved: 2025-08-24

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0 ;
        for(int i = nums.size()-1 ; i >= 1; i= i-2){
            sum += min(nums[i],nums[i-1]);
        }
        return sum ;
        
    }
};
