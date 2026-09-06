// 746. Min Cost Climbing Stairs
// https://leetcode.com/problems/min-cost-climbing-stairs/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 17.7 MB
// Solved: 2026-01-22

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n);
        if(cost.size() == 1){
            return cost[0];
        }
        dp[0]= cost[0];
        dp[1] = cost[1]; 
        for(int i = 2 ; i< n ;i++){
            dp[i] = cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};
