// 415. Add Strings
// https://leetcode.com/problems/add-strings/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 9.2 MB
// Solved: 2025-08-25

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0 ;
        string s = "";

        while(i >= 0 || j >= 0 || carry > 0 ){
            int x = (i >= 0) ? (num1[i] - '0'):0;
            int y = ( j>= 0) ? (num2[j] - '0'):0;
            int sum = x+y+carry;
            s.push_back((sum%10)+'0');
            carry = sum/10;
            i--;
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
        
    }
};
