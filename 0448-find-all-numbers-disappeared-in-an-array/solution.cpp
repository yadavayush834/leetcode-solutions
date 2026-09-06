// 448. Find All Numbers Disappeared in an Array
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// Difficulty: Easy | Language: cpp
// Runtime: 6 ms
// Memory: 52.8 MB
// Solved: 2025-09-26

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans ; 
        for(int i =0 ; i< nums.size(); i++){
            int index = abs(nums[i]) - 1; 
            if(nums[index] > 0){
                nums[index] = -(nums[index]);

            }
            

        }
        for(int i =0 ; i < nums.size() ; i++){
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
        }
        return ans ;
    }
};
