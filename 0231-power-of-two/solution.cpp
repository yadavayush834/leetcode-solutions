// 231. Power of Two
// https://leetcode.com/problems/power-of-two/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 7.9 MB
// Solved: 2025-08-21

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        bitset<32>b(n);
        return b.count() == 1;

        
    }
};
