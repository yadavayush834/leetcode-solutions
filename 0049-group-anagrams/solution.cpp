// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/
// Difficulty: Medium | Language: cpp
// Runtime: 10 ms
// Memory: 24.8 MB
// Solved: 2025-08-28

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>ans;

        for(string &s : strs){
            string key = s;
            sort(key.begin(),key.end());
            ans[key].push_back(s);
        }
        vector<vector<string>>result;
        for(auto &entry : ans){
            result.push_back(entry.second);
        }
        return result;
        
    }
};
