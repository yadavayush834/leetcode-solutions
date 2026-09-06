// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 9.1 MB
// Solved: 2025-08-19

class Solution {
public:
    bool isValid(string s) {
        stack<char>stack;
        unordered_map<char,char>mapping = {{')','('},{']','['},{'}','{'}};
        for (char c:s){
            if(mapping.find(c) == mapping.end()){
                stack.push(c);
            }
            else if(!stack.empty() && mapping[c] == stack.top()){
                stack.pop();
            }
            else{
                return false;
            }
        }
        return stack.empty();


        
    }
};
