// 205. Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/
// Difficulty: Easy | Language: cpp
// Runtime: 3 ms
// Memory: 9.5 MB
// Solved: 2025-08-23

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,char>mpp1;
        unordered_map<char,char>mpp2;

        for(int i = 0 ; i<s.length(); i++){
            char sc = s[i] , tc = t[i];
            if(mpp1.count(sc) && mpp1[sc] != tc) return false;
            if(mpp2.count(tc) && mpp2[tc] != sc) return false;
            mpp1[sc] = tc;
            mpp2[tc] = sc;
        }
        return true;

        
    }
};
