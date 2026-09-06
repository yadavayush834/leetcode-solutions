// 202. Happy Number
// https://leetcode.com/problems/happy-number/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 7.8 MB
// Solved: 2025-08-24

class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getnext(n);
        while(n != 1 && slow != fast)
        {
            slow = getnext(slow);
            fast = getnext(getnext(fast));
            
        }
        return fast == 1;
        
    }

    private:
        int getnext(int n){
            int sum = 0 ;
            int d = 0;
            while(n > 0 ){
                d = n %10;
                sum += d*d;
                n = n /10;
            }
            return sum;
        }
};
