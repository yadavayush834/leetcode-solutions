// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Difficulty: Medium | Language: cpp
// Runtime: 0 ms
// Memory: 15.1 MB
// Solved: 2025-08-28

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] >= nums[low]){
                if(target >= nums[low] && nums[mid] >= target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid+1;

                }
                else{
                    high = mid -1;
                }
            }
        }
        return -1;
        
    }
};
