// 1748. Sum of Unique Elements
// https://leetcode.com/problems/sum-of-unique-elements/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 10.7 MB
// Solved: 2025-10-04

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int>mpp ;
        for(int i= 0; i< nums.size(); i++){
            mpp[nums[i]]++;
        }
        int sum = 0 ; 
        for(auto &entry : mpp){
            if(entry.second == 1){
                sum += entry.first;
            }
        }
        return sum;

        
    }
};
