// 680. Valid Palindrome II
// https://leetcode.com/problems/valid-palindrome-ii/
// Difficulty: Easy | Language: cpp
// Runtime: 13 ms
// Memory: 35.6 MB
// Solved: 2026-08-15

class Solution {
public:

    bool checkp(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {

            if (s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                string s1 = s;
                s1.erase(i, 1);

                if (checkp(s1))
                    return true;

                string s2 = s;
                s2.erase(j, 1);

                if (checkp(s2))
                    return true;

                return false;
            }
        }

        return true;
    }
};
