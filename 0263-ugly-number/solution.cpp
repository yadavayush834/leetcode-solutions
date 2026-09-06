// 263. Ugly Number
// https://leetcode.com/problems/ugly-number/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 7.8 MB
// Solved: 2025-08-24

class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false; 
        while(n %2 == 0 ){
            n = n/2;
        }
        while(n %3 == 0){
            n = n /3;
        }
        while(n % 5  ==0 ){
            n = n /5;
        }
        return n == 1;
        
    }
};
