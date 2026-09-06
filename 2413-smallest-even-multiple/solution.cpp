// 2413. Smallest Even Multiple
// https://leetcode.com/problems/smallest-even-multiple/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8 MB
// Solved: 2025-03-30

class Solution {
public:
    int smallestEvenMultiple(int n) {
        int ans = -1;
        for(int i = 1 ; i< 303; i++){
            
            if(i% n == 0 && i%2 == 0){
                ans = i;
                break;
            }
        }
        return ans;
        
    }
};
