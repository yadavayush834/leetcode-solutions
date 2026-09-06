#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        
 
        while (ss >> word) {
            words.push_back(word);
        }
        
        
        if (words.size() != pattern.size()) return false;
        
        unordered_map<char, string> mp;
        unordered_set<string> used;
        
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            
            if (mp.count(c)) {
                
                if (mp[c] != w) return false;
            } else {
              
                if (used.count(w)) return false;
                mp[c] = w;
                used.insert(w);
            }
        }
        
        return true;
    }
};
