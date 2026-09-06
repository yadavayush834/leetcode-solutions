// 389. Find the Difference
// https://leetcode.com/problems/find-the-difference/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 9.5 MB
// Solved: 2025-08-23

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mpp;

       
        for (char c : s) {
            mpp[c]++;
        }

       
        for (char c : t) {
            if (mpp.find(c) == mpp.end() || mpp[c] == 0) {
                
                return c;
            }
            mpp[c]--;
        }

        
        return '\0';
    }
};
