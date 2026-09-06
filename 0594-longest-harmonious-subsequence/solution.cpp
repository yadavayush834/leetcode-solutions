// 594. Longest Harmonious Subsequence
// https://leetcode.com/problems/longest-harmonious-subsequence/
// Difficulty: Easy | Language: cpp
// Runtime: 41 ms
// Memory: 44.1 MB
// Solved: 2026-08-23

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++; 
        }
        int ans = 0 ; 

        for(auto it:mpp){
            int x = it.first;
            int y = it.second;

            if(mpp.find(x+1) != mpp.end()){
                ans = max(ans,y+mpp[x+1]);
            }
        }
        return ans; 
    }
};
