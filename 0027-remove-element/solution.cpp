// 27. Remove Element
// https://leetcode.com/problems/remove-element/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 11.6 MB
// Solved: 2025-08-28

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        long long k = 0 ;
        for(auto it: nums){
            if(it != val){
                nums[k] = it ;
                k++;

            }
        }
        return k ; 
        
    }
};
