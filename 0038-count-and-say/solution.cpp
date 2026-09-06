// 38. Count and Say
// https://leetcode.com/problems/count-and-say/
// Difficulty: Medium | Language: cpp
// Runtime: 6 ms
// Memory: 10.1 MB
// Solved: 2025-09-27

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";  
    
        string prev = countAndSay(n - 1);  
        string result = "";
        int count = 1;
    
        for (int i = 1; i < prev.size(); i++) {
            if (prev[i] == prev[i - 1]) {
                count++;  
            } 
            else {
                result += to_string(count) + prev[i - 1]; 
                count = 1;
            }
        }
    result += to_string(count) + prev.back(); 
    return result;
}


    
};
