// 344. Reverse String
// https://leetcode.com/problems/reverse-string/
// Difficulty: Easy | Language: cpp
// Runtime: 11 ms
// Memory: 27.2 MB
// Solved: 2024-07-11

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0; 
        int end = s.size()-1;
        while(start< end){
            swap(s[start++] , s[end--]);

        }
    
        
    }
};
