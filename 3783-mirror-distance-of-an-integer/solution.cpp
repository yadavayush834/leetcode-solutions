// 3783. Mirror Distance of an Integer
// https://leetcode.com/problems/mirror-distance-of-an-integer/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8.5 MB
// Solved: 2026-04-18

class Solution {
public:
    int mirrorDistance(int n) {
        int mirror = 0, a = n;
        while (a) {
            mirror = mirror * 10 + (a % 10);
            a /= 10;
        }
        return abs(n - mirror);
    }
};
