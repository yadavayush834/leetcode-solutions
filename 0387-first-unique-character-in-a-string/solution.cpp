// 387. First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/
// Difficulty: Easy | Language: cpp
// Runtime: 12 ms
// Memory: 14.9 MB
// Solved: 2025-08-23

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mpp;
        for(char c:s){
            mpp[c]++;
        }
        for(int i = 0 ; i< s.size(); i++){
            if(mpp[s[i]] ==1){
                return i;
            }
        }
        return -1;
        
    }
};
