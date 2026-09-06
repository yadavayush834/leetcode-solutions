// 28. Find the Index of the First Occurrence in a String
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8.6 MB
// Solved: 2025-07-12

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = haystack.length();
        int len2 = needle.length();
        int i = 0 ;
        int j = 0;

        while(i < len){
            if(haystack[i] == needle[j]){
                if(j == len2 - 1){
                    return i -j ;
                }
                i++;
                j++;
            }
            else{
                
                i = i - j + 1;
                j = 0 ;

            }
        }
        return -1;
        
    }
};
