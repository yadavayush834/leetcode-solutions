// 984. String Without AAA or BBB
// https://leetcode.com/problems/string-without-aaa-or-bbb/
// Difficulty: Medium | Language: cpp
// Runtime: 3 ms
// Memory: 8.1 MB
// Solved: 2026-02-09

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";
        int counta = 0;
        int countb = 0;

       
        while (a > 0 || b > 0) {

          
            if (counta == 2 && b > 0) {
                ans += 'b';
                b--;
                countb = 1;
                counta = 0;
            }
          
            else if (countb == 2 && a > 0) {
                ans += 'a';
                a--;
                counta = 1;
                countb = 0;
            }
           
            else if (a >= b && a > 0) {
                ans += 'a';
                a--;
                counta++;
                countb = 0;
            }
            else if (b > 0) {
                ans += 'b';
                b--;
                countb++;
                counta = 0;
            }
        }

        return ans;
    }
};
