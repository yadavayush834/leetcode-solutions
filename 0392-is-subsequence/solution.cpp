// 392. Is Subsequence
// https://leetcode.com/problems/is-subsequence/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8.6 MB
// Solved: 2025-08-25

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // as it is a subsequence hence order of the characters matter
        int i =0 ;
        int j =0 ; 
        while(i < s.size() && j < t.size()){
            if(s[i] == t[j]){
                i++;
                
                
            }
            j++;
           
        }
        return i == s.size();
    }
};
