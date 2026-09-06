// 441. Arranging Coins
// https://leetcode.com/problems/arranging-coins/
// Difficulty: Easy | Language: cpp
// Runtime: 11 ms
// Memory: 8.9 MB
// Solved: 2025-07-11

class Solution {
public:
    int arrangeCoins(int n) {
        int a = n ;
        int ans = 0 ;
        for(int i = 1; i <= n ; i++){
            if(a < i){
                break;
            }
            else{
                a = a - i;
                ans++;
            }
        }
        return ans;
        
    }
};
