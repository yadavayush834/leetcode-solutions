// 1486. XOR Operation in an Array
// https://leetcode.com/problems/xor-operation-in-an-array/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 7.8 MB
// Solved: 2025-08-29

class Solution {
public:
    int xorOperation(int n, int start) {
        int i =0 ; 
        int xori = 0 ;
        while(n--){
            int value = start + 2*i;
            i++;
            xori ^= value;

        }
        return xori;
        
    }
};
