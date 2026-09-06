// 925. Long Pressed Name
// https://leetcode.com/problems/long-pressed-name/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8.8 MB
// Solved: 2025-10-04

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0; 
        int j = 0;
        
        while (i < typed.size()) {
            if (j < name.size() && name[j] == typed[i]) {
                j++;
                i++;
            }
            else if (i > 0 && typed[i] == typed[i-1]) {
                i++;
            }
            else {
                return false;
            }
        }
        
        return j == name.size();
    }
};
