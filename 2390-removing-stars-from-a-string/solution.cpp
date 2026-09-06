// 2390. Removing Stars From a String
// https://leetcode.com/problems/removing-stars-from-a-string/
// Difficulty: Medium | Language: cpp
// Runtime: 19 ms
// Memory: 28.4 MB
// Solved: 2025-09-26

class Solution {
public:
    string removeStars(string s) {
    
        string ans;
        for (char c : s) {
            if (c == '*') {
                if (!ans.empty()) ans.pop_back();  
            } else {
                ans.push_back(c);                  
            }
        }
        return ans;
}

        
    
};
