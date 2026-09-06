// 3950. Exactly One Consecutive Set Bits Pair
// https://leetcode.com/problems/exactly-one-consecutive-set-bits-pair/
// Difficulty: Easy | Language: cpp
// Runtime: 2 ms
// Memory: 7.9 MB
// Solved: 2026-08-04

class Solution {
public:
    bool consecutiveSetBits(int n) {
        bitset<32>bs(n);
        int count = 0 ;
        for(int i = 0; i< 30; i++){
            if(bs[i] && bs[i + 1]){
                count++;
                
            }
        }
        if(count == 1){
            return true;
        }
        return false;
        
    }
};
