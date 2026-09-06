// 485. Max Consecutive Ones
// https://leetcode.com/problems/max-consecutive-ones/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 50.2 MB
// Solved: 2025-03-29

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, r = 0, maxlen = 0;
        int n = nums.size();
        while(r<n){
            if(nums[r] == 0){
                r = r+1;
                l = r;
            }
            else if(nums[l] == 0){
                l = l +1;
            }
            else{
                maxlen = max(maxlen,r-l+1);
                r = r+1;

            }
            

        }
        return maxlen;
        
    }
};
