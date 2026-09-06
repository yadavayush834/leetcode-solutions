// 58. Length of Last Word
// https://leetcode.com/problems/length-of-last-word/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8.9 MB
// Solved: 2025-07-12

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;
        int count = 0;
        while(i >= 0 && s[i] == ' '){
            i--;
        }
        while(i >= 0 && s[i] != ' '){
            count = count + 1;
            i--;
        }
        return count;
        
    }
};
