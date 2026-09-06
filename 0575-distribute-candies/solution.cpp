// 575. Distribute Candies
// https://leetcode.com/problems/distribute-candies/
// Difficulty: Easy | Language: cpp
// Runtime: 106 ms
// Memory: 120 MB
// Solved: 2025-10-03

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int>mpp ;
        for(int i =0 ; i< candyType.size() ; i++){
            mpp[candyType[i]]++;

        }
        int eat = candyType.size()/2;
        int ans = 0 ;
        for(int i =0 ; i< mpp.size() ; i++){
           if(ans < eat) {
                ans++;
           }
        }
        return ans;
        
    }
};
