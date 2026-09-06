// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Difficulty: Easy | Language: cpp
// Runtime: 3 ms
// Memory: 22.7 MB
// Solved: 2025-08-28

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int write = 1;                     
        for (int read = 1; read < n; ++read) {
            if (nums[read] != nums[write - 1]) {
                nums[write] = nums[read];  
                ++write;                   
            }
        }
        return write;                      
    }
};
