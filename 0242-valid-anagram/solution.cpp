// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/
// Difficulty: Easy | Language: cpp
// Runtime: 4 ms
// Memory: 9.6 MB
// Solved: 2025-07-11


class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s == t){
            return true;
        
        }
        return false;
    }
};
