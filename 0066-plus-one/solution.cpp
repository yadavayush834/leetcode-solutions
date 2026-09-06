// 66. Plus One
// https://leetcode.com/problems/plus-one/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 11.4 MB
// Solved: 2025-03-30

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        if(digits[i]!= 9){
            digits[i] = digits[i] + 1;
        }
        else{
            
            while(i>=0 && digits[i] == 9){
                digits[i] = 0;
                i = i -1;
            }
            if (i >= 0)
                digits[i] = digits[i] + 1;
            else
                digits.insert(digits.begin(), 1);
            
        }

        return digits;
        
    }
};
