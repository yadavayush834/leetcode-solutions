// 3345. Smallest Divisible Digit Product I
// https://leetcode.com/problems/smallest-divisible-digit-product-i/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 9.2 MB
// Solved: 2026-08-31

class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = -1; 
        for(int i = n ; i <= 100 ; i++){

            string s = to_string(i);
            int product = 1 ;
            for(int j = 0; j < s.size(); j++){
                int a = s[j] - '0';
                product = product * a ;
            }
            if(product % t == 0){
                ans = i ; 
                break;
            }
        }
        return ans; 
    }
};
