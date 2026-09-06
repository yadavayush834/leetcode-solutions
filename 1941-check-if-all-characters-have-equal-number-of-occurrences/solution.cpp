// 1941. Check if All Characters Have Equal Number of Occurrences
// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/
// Difficulty: Easy | Language: cpp
// Runtime: 3 ms
// Memory: 9.7 MB
// Solved: 2025-08-24

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>mpp;
        for(auto it:s){
            if(mpp.find(it) != mpp.end()){
                mpp[it]++;
            }
            else{
                mpp[it] = 1;
            }
        }
        int check = mpp[s[0]];
        for(int i =1 ; i< s.size(); i++){
            if(mpp[s[i]] != check){
                return false;
            }
        }
        return true;
    }
};
