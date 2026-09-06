// 1768. Merge Strings Alternately
// https://leetcode.com/problems/merge-strings-alternately/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8.4 MB
// Solved: 2025-09-26

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n = word1.size();
        int m = word2.size();
        int i = 0 ;
        int j = 0 ; 
        int k = 0 ; 
        while(i <= n+m){
            if(j < n){
                ans += word1[j++];
            }
            if(k < m ){
                ans += word2[k++];

            }
            i++;
            

        }
        return ans;
        
    }
};
