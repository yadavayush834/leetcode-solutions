// 2733. Neither Minimum nor Maximum
// https://leetcode.com/problems/neither-minimum-nor-maximum/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 97.2 MB
// Solved: 2025-09-28

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() < 3){
            return -1 ;
        }        
        else{
            int a = min (nums[0],nums[1]);
            int b =  max(nums[0],nums[1]);
            int c = nums[2];
            if(c < b && c > a) return c ;
            if(c < a) return a ;
            if(c > b) return b;
            return -1;
        }
    }
};
