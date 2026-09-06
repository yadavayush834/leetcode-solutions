// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/
// Difficulty: Easy | Language: cpp
// Runtime: 1 ms
// Memory: 8.5 MB
// Solved: 2025-09-23

class Solution {
public:
    int climbStairs(int n) {
        if(n <=2 ){
            return n ; 
        }
        vector<int>dp ( n +1); 
        dp[1] = 1; 
        dp[2] = 2; 
        for(int i = 3 ; i <= n ; i++){
            dp[i] = dp[i-1]+ dp[i-2];
        }
        return dp[n];
        
    }
};
