// 917. Reverse Only Letters
// https://leetcode.com/problems/reverse-only-letters/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8.2 MB
// Solved: 2025-08-25

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0 ; 
        int j = s.size()-1; 
        while( i <= j ){
                if(isalpha(s[i]) && isalpha(s[j])){
                    char temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                    i++;
                    j--;
                }
                else if(isalpha(s[i])){
                    j--;
                }
                else{
                    i++;
                }
        }
        return s;
        
    }
};
