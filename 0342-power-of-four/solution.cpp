// 342. Power of Four
// https://leetcode.com/problems/power-of-four/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8 MB
// Solved: 2025-08-25

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n ==1) return true;
        else{
            while(n >=1){
                if( n == 1 ) return true;
                else{
                   if(n %4 == 0 ){
                    n = n /4;
                   }
                   else{
                    return false;
                   }
                }
            }
            return false;
        }
        
    }
};
