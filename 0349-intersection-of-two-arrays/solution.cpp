// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/
// Difficulty: Easy | Language: cpp
// Runtime: 3 ms
// Memory: 14.9 MB
// Solved: 2025-08-19

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr;
        map<int,int>mpp1;
        map<int,int>mpp2;
        for(auto it:nums1){
            mpp1[it]++;
        }
        for(auto it:nums2){
            mpp2[it]++;
        }
        for(auto it:mpp1){
            if(mpp2.find(it.first) != mpp2.end()){
                arr.push_back(it.first);
            }
        }
        return arr;
        
    }
    
};
