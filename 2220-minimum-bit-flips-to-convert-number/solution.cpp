// 2220. Minimum Bit Flips to Convert Number
// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 7.9 MB
// Solved: 2026-08-13

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xori = start ^ goal;
        int ans = __builtin_popcount(xori);
        return ans; 
    }
};
