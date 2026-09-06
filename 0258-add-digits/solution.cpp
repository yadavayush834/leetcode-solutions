// 258. Add Digits
// https://leetcode.com/problems/add-digits/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8.6 MB
// Solved: 2025-03-30

class Solution {
public:
    int addDigits(int num) {
        return (num -1)%9 +1;
        
    }
};
