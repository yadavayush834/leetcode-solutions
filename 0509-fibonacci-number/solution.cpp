// 509. Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/
// Difficulty: Easy | Language: cpp
// Runtime: 3 ms
// Memory: 7.7 MB
// Solved: 2025-08-21

class Solution {
public:
    int fib(int n) {
        long long int first = 0 ;
        long long int second = 1;
        long long int third;
        if(n == 0) return 0;
        for(int i = 2; i<= n ; i++){
            third = first + second;
            first = second;
            second = third;
        }
        return third;
        
    }
};
