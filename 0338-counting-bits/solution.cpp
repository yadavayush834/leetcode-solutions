// 338. Counting Bits
// https://leetcode.com/problems/counting-bits/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 10.7 MB
// Solved: 2026-06-08

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i = 1; i <=n ; i++){
            ans[i] = ans[i >> 1] + (i&1);
        }

        return ans;
        
    }
};
