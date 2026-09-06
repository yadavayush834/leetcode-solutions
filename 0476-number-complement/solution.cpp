// 476. Number Complement
// https://leetcode.com/problems/number-complement/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8.1 MB
// Solved: 2025-07-12

class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        int digits = log2(num)+1;
        int all  = pow(2,digits)-1;
        return all - num;

        
    }
};
