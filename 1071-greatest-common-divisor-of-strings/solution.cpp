// 1071. Greatest Common Divisor of Strings
// https://leetcode.com/problems/greatest-common-divisor-of-strings/
// Difficulty: Easy | Language: cpp
// Runtime: 2 ms
// Memory: 9.8 MB
// Solved: 2025-09-26

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1){
            return "";
        }
        int g = gcd(str1.size(), str2.size());
        return str2.substr(0,g);
        
    }
};
