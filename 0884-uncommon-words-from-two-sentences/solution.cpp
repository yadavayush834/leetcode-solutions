// 884. Uncommon Words from Two Sentences
// https://leetcode.com/problems/uncommon-words-from-two-sentences/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 9.2 MB
// Solved: 2025-10-04

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mpp;
        string word;

    
        stringstream ss(s1);
        while (ss >> word) {
            mpp[word]++;
        }

    
        stringstream ww(s2);
        while (ww >> word) {
            mpp[word]++;
        }

        vector<string> result;
        
        for (auto &entry : mpp) {
            if (entry.second == 1) { 
                result.push_back(entry.first);
            }
        }

        return result;
    }
};
