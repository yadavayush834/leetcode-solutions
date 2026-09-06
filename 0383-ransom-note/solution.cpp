// 383. Ransom Note
// https://leetcode.com/problems/ransom-note/
// Difficulty: Easy | Language: cpp
// Runtime: 4 ms
// Memory: 12 MB
// Solved: 2025-08-23

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mpp;
        for(int i = 0; i < magazine.size(); i++){
            mpp[magazine[i]]++;
        }

        for(int i = 0 ; i < ransomNote.size();i++){
            if(mpp[ransomNote[i]] <= 0){
                return false;
            }
            mpp[ransomNote[i]]--;
        }
        return true;
        
    }
};
