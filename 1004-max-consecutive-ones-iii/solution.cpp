// 1004. Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii/
// Difficulty: Medium | Language: cpp
// Runtime: 3 ms
// Memory: 69.6 MB
// Solved: 2026-09-06

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j = 0 ;
        int z = 0 ;
        int maxi = 0 ;
        for(int i = 0 ; i< nums.size(); i++){
            if(nums[i] == 0){
                z++;
            }   
            while(z > k ){
                if(nums[j] == 0){
                    z--;
                }
                j++;
            }
            maxi = max(i-j+1, maxi);
        }
        return maxi; 
    }
};
