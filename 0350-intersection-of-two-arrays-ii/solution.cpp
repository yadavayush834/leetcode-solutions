// 350. Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 15 MB
// Solved: 2025-08-24

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr;
        unordered_map<int,int>mpp;
        for(auto it : nums1){
            if(mpp.find(it) != mpp.end()){
                mpp[it]++;
            }
            else{
                mpp[it] = 1;
            }
            
        }
        for(int i =0 ; i< nums2.size();i++){
            if(mpp[nums2[i]] > 0){
                arr.push_back(nums2[i]);
                mpp[nums2[i]]--;
            }
        }
        return arr;
        
    }
};
