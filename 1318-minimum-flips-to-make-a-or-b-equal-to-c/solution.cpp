// 1318. Minimum Flips to Make a OR b Equal to c
// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
// Difficulty: Medium | Language: cpp
// Runtime: 0 ms
// Memory: 7.6 MB
// Solved: 2026-08-13

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0 ; 
        int ori = a | b ; 
        int t= ori ^c;
        if(!t) return 0 ; 
        else{
            bitset<32>b3(a);
            bitset<32>b4(b);
            bitset<32>b1(ori);
            bitset<32>b2(c);
           
            for(int i =0 ; i<32; i++){
               if(b1[i] != b2[i]){
                if(b2[i] == 1){
                    ans += 1; 
                }
                else{
                    if(b3[i] == b4[i]){
                        ans += 2;
                    }
                    else{
                        ans += 1; 
                    }
                }
               }
               
            }
        }
        return ans; 
        
    }
};
