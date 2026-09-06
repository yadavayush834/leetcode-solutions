// 1647. Minimum Deletions to Make Character Frequencies Unique
// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
// Difficulty: Medium | Language: cpp
// Runtime: 8 ms
// Memory: 20.5 MB
// Solved: 2025-10-11

class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        for(char ch : s){
            freq[ch-'a']++;
        }
        int result = 0 ; 
        unordered_set<int>st ;
        for(int i = 0 ; i<26; i++){
            while(freq[i] && st.find(freq[i]) != st.end()){
                freq[i]--;
                result++;
            }
            st.insert(freq[i]);
        }
        return result;
    }
};
