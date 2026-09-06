// 67. Add Binary
// https://leetcode.com/problems/add-binary/
// Difficulty: Easy | Language: cpp
// Runtime: 3 ms
// Memory: 8.9 MB
// Solved: 2025-08-23

class Solution {
public:
    string addBinary(string a, string b) {
        int as = a.size()-1;
        int bs = b.size()-1;
        string s = "";
        int carry = 0 ;
        int sum = 0;
        while(as >= 0 || bs >=0 || carry){
            int sum = carry;
            if(as>= 0) sum += a[as--]-'0';
            if(bs >= 0) sum += b[bs--]-'0';

            s.push_back((sum%2) + '0');
            carry = sum/2;
        }
        reverse(s.begin(),s.end());
        return s;
        
    }
};
