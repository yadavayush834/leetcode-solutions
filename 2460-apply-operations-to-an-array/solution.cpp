// 2460. Apply Operations to an Array
// https://leetcode.com/problems/apply-operations-to-an-array/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 13.2 MB
// Solved: 2025-10-05

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>result;
        for(int i =0 ; i< nums.size(); i++){
            if(i != nums.size()-1 && nums[i] == nums[i+1]){
                nums[i] *=2; 
                nums[i+1] = 0 ;
            }
        }
        int count = 0; 
        for(int i = 0 ; i< nums.size(); i++){
            if(nums[i] == 0){
                count++;
            }
            else{
                result.push_back(nums[i]);
            }
           
        }
        while(count--){
            result.push_back(0);
        }
        return result;
        
        


        
    }
};
