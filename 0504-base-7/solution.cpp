// 504. Base 7
// https://leetcode.com/problems/base-7/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8.2 MB
// Solved: 2026-01-27

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }
        bool isneg = num<0 ;
        num = abs(num);
        string ans = "";
        while(num > 0){
            ans += to_string(num%7);
            num /= 7;
        }
        if(isneg){
            ans += "-";
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};
