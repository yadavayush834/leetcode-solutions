// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 12.2 MB
// Solved: 2025-08-19

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string str = strs[0];
        int strlen = strs[0].length();

        for(int i = 1; i < strs.size();i++){
            string s = strs[i];
            while(strlen > strs[i].length() || str != s.substr(0,strlen)){
                strlen--;
                if(strlen == 0 ) return "";
                str = str.substr(0,strlen);
            }
        }
        return str;

        
    }
};
