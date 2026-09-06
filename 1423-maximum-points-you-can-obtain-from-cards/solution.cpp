// 1423. Maximum Points You Can Obtain from Cards
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Difficulty: Medium | Language: cpp
// Runtime: 0 ms
// Memory: 46.3 MB
// Solved: 2025-04-13

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int j = n -1; 
        int maxsum = 0 ;
        int sum = 0 ; 
        for(int i = 0 ; i<k ; i++){
            sum += cardPoints[i];
            maxsum = sum;
        }
        for(int i = k-1; i >= 0 ; i--){
            sum = sum - cardPoints[i] + cardPoints[j];
            j--;
            maxsum = max(sum,maxsum);
        }
        return maxsum;
        
    }
};
