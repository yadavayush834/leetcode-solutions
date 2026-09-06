// 2824. Count Pairs Whose Sum is Less than Target
// https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 24.7 MB
// Solved: 2026-02-01

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int low = 0 ;
        int high = nums.size()-1; 
        int pair =  0; 
        while(low <= high){
            if(nums[low] + nums[high] < target){
                pair = (high-low) + pair ; 
                low++ ;
            }
            else{
                high-- ;
            }
        }
        return pair;
    }
};
