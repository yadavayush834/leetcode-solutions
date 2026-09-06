// 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/
// Difficulty: Easy | Language: cpp
// Runtime: 4 ms
// Memory: 10.8 MB
// Solved: 2025-08-23

class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char,int> mpp = {
            {'a',1},{'e',1},{'i',1},{'o',1},{'u',1},
            {'A',1},{'E',1},{'I',1},{'O',1},{'U',1}
        };

        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (mpp.find(s[i]) != mpp.end() && mpp.find(s[j]) != mpp.end()) {
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                i++;
                j--;
            }
            else if (mpp.find(s[i]) != mpp.end() && mpp.find(s[j]) == mpp.end()) {
                j--;
            }
            else {
                i++;
            }
        }
        return s;
    }
};
