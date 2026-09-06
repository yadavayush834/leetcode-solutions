// 507. Perfect Number
// https://leetcode.com/problems/perfect-number/
// Difficulty: Easy | Language: cpp
// Runtime: 2089 ms
// Memory: 7.7 MB
// Solved: 2026-08-15

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0; 
        for (int i = 1; i < num ; i++){
            if(num % i == 0){
                sum += i;
            }
        }
        if(sum == num){
            return true;
        }
        else{
            return false;
        }
    }
};
