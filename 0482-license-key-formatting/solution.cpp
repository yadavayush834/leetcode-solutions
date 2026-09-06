// 482. License Key Formatting
// https://leetcode.com/problems/license-key-formatting/
// Difficulty: Easy | Language: cpp
// Runtime: 6 ms
// Memory: 10.6 MB
// Solved: 2025-07-12

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        int count = 0 ; 
        for(int i = s.length()-1; i>= 0;i--){
            if(s[i] == '-'){
                continue;
            }
            if(count == k){
                res.push_back('-');
                count = 0;
            }
            res += toupper(s[i]);
            ++count;
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};
