// 1009. Complement of Base 10 Integer
// https://leetcode.com/problems/complement-of-base-10-integer/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 7.9 MB
// Solved: 2025-07-12

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int digit = log2(n)+1;
        int all = pow(2,digit)-1;
        return all -n;
        
    }
};
