#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(),
                  [](unsigned char c){ return tolower(c); });
        s = regex_replace(s, regex("[^a-z0-9]"), ""); // keep digits

        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};
