// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Difficulty: Medium | Language: cpp
// Runtime: 59 ms
// Memory: 19.4 MB
// Solved: 2026-09-06

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mpp; 
        int maxi = 0 ; 
        int j = 0 ;
        for(int i = 0 ; i< s.size(); i++){
            mpp[s[i]]++;
            while(mpp[s[i]] > 1){
                
                mpp[s[j]]--;
                j++; 
                
            }
            maxi = max(i-j+1,maxi);
            
        }
        return maxi ; 
    }
};
