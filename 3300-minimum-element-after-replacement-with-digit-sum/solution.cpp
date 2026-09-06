// 3300. Minimum Element After Replacement With Digit Sum
// https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 27.8 MB
// Solved: 2026-05-29

class Solution {
public:
    int sumofdigits(int n){
        int a = n ;
        int ans = 0 ; 
        while(a != 0){
            ans += a%10 ;
            a = a /10 ; 
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        int t = INT_MAX;
        for(int i = 0 ; i< nums.size() ; i++){
            int s = sumofdigits(nums[i]);
            nums[i] = s; 
            t= min(t,nums[i]);
        }
        return t;
        
        
    }
};
