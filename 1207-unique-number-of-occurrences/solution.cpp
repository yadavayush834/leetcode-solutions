// 1207. Unique Number of Occurrences
// https://leetcode.com/problems/unique-number-of-occurrences/
// Difficulty: Easy | Language: cpp
// Runtime: 3 ms
// Memory: 12 MB
// Solved: 2026-04-18

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> a;
        
        for(int b : arr){
            a[b]++;
        }
        
        unordered_set<int> c;
        
        for(auto d : a){
            c.insert(d.second);
        }
        
        return a.size() == c.size();
    }
};
