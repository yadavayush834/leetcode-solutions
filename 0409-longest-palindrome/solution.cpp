// 409. Longest Palindrome
// https://leetcode.com/problems/longest-palindrome/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 9.3 MB
// Solved: 2025-08-24

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mpp;
        for (char c : s) {
            mpp[c]++;
        }

        int ans = 0;
        bool oddFound = false;
        
        for (auto it : mpp) {
            if (it.second % 2 == 0) {
                ans += it.second;               
            } else {
                ans += it.second - 1;          
                oddFound = true;           
            }
        }

        if (oddFound) ans += 1;
        return ans;
    }
};
