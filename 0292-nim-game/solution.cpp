// 292. Nim Game
// https://leetcode.com/problems/nim-game/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 7.9 MB
// Solved: 2025-08-24

class Solution {
public:
    bool canWinNim(int n) {
        return n%4 !=0;
    }
};
