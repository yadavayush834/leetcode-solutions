// 167. Two Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Difficulty: Medium | Language: cpp
// Runtime: 0 ms
// Memory: 19.6 MB
// Solved: 2025-04-13

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        int l = 0 ;
        int r = n-1;
        while(l<r){
            int sum = numbers[l]+numbers[r];
            if(sum == target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
                
            }
            else if(sum< target){
                l++;
            }
            else if(sum > target){
                r--;
                
            }
            
        }
        return ans;
        
    }
};
