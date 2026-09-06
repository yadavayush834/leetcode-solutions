// 709. To Lower Case
// https://leetcode.com/problems/to-lower-case/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8.1 MB
// Solved: 2026-01-28

class Solution {
public:
    string toLowerCase(string s) {
        for (char &c : s) {
            c = tolower(c);
        }
        return s;
    }
};
