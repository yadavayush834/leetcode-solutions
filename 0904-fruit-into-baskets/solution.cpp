// 904. Fruit Into Baskets
// https://leetcode.com/problems/fruit-into-baskets/
// Difficulty: Medium | Language: cpp
// Runtime: 47 ms
// Memory: 84.8 MB
// Solved: 2026-09-06

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int j = 0 ; 
        int maxi = 0 ;
        unordered_map<int,int>mpp;
        for(int i = 0 ; i < fruits.size(); i++){
            mpp[fruits[i]]++;

            while(mpp.size() > 2){
                mpp[fruits[j]]--;
                if(mpp[fruits[j]] == 0){
                    mpp.erase(fruits[j]);
                }
                j++;
            }
            maxi = max(i-j+1, maxi);

        }
        return maxi ; 

    }
};
