// 434. Number of Segments in a String
// https://leetcode.com/problems/number-of-segments-in-a-string/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8.2 MB
// Solved: 2025-08-25

class Solution {
public:
    int countSegments(string s) {
        int count = 0 ; 
        for(int i =0 ; i< s.size(); i++){
            if(s[i] != ' ' && (i == 0 || s[i-1] == ' ')){
                count++;
            }
        }
        return count;
    }
};
