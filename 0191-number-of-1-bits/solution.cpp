// 191. Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8.4 MB
// Solved: 2025-09-28

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0 ; 
        while(n){ 
            count += n & 1 ; 
            n >>= 1 ;
            
        }
        return count;
        
    }
};
