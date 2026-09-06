// 357. Count Numbers with Unique Digits
// https://leetcode.com/problems/count-numbers-with-unique-digits/
// Difficulty: Medium | Language: cpp
// Runtime: 0 ms
// Memory: 7.9 MB
// Solved: 2026-08-19

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 0; 
        int current = 1 ; 
        if(n == 0) return 1;
        for(int digit = 1 ; digit <= n ; digit++){
            if(digit == 1){
                current = 10 ;
            }
            else if(digit == 2){
                current = 9*9 ;
            }
            else{
                current = current * (11 - digit);
            }
            ans += current;
        }
        return ans;
    }
};
