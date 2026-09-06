// 1952. Three Divisors
// https://leetcode.com/problems/three-divisors/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 7.6 MB
// Solved: 2025-03-30

class Solution {
public:
    bool isThree(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++){
            if(n % i == 0){
                count++;
            }
        }
        if(count == 3){
            return true;
        }
        else{
            return false;
        }
        
    }
};
