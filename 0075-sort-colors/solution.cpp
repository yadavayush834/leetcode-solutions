// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/
// Difficulty: Medium | Language: cpp
// Runtime: 5 ms
// Memory: 11.5 MB
// Solved: 2025-08-28

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0 ; 
        int one = 0;
        int two = 0 ;
        for(int i = 0 ; i< nums.size(); i++){
            if(nums[i] == 0){
                zero++;
            }
            else if(nums[i] == 1){
                one++;
            }
            else{
                two++;
            }

        }
        int i =0 ; 
        while(zero || one || two){
            if(zero){
                nums[i] = 0;
                zero--;
                i++;
            }
            else if(one){
                nums[i] = 1;
                one--;
                i++;
            }
            else{
                nums[i] = 2;
                i++;
                two--;
            }
        }
        for(auto it : nums){
            cout<<it;
        }
        
    }
};
