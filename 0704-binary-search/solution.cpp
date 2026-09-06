// 704. Binary Search
// https://leetcode.com/problems/binary-search/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 31.4 MB
// Solved: 2025-08-28

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low= 0  ;
        int high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
        
    }
};
