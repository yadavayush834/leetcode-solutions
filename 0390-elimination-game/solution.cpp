// 390. Elimination Game
// https://leetcode.com/problems/elimination-game/
// Difficulty: Medium | Language: cpp
// Runtime: 0 ms
// Memory: 9.6 MB
// Solved: 2026-08-19

class Solution {
public:
    int solve(int head,int step , int remaining, bool left){
        if(remaining == 1){
            return head;
        }
        if(left || remaining%2 == 1){
            head += step;
        }

        remaining = remaining /2 ;
        step = step * 2; 
        left = !left; 
        return solve(head, step ,remaining ,left);

    }
    int lastRemaining(int n) {
        return solve(1,1,n,true);
    }
};
