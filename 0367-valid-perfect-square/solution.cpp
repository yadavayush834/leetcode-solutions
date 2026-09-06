// 367. Valid Perfect Square
// https://leetcode.com/problems/valid-perfect-square/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 7.9 MB
// Solved: 2025-08-25

class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long long int i =1 ; i*i<=num ; i++){
            if(i*i == num){
                return true;
            }
        }
        return false;
        
    }
};
