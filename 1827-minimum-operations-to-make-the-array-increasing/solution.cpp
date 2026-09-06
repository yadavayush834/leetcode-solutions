// 1827. Minimum Operations to Make the Array Increasing
// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
// Difficulty: Easy | Language: cpp
// Runtime: 8 ms
// Memory: 19.4 MB
// Solved: 2025-08-20

class Solution {
public:
    int minOperations(vector<int>& nums) {
        long long int moves = 0 ;
        long long int moves2 = 0;
        for(int i = 1 ; i< nums.size(); i++){
            if(nums[i-1]>=nums[i]){
                moves2 = nums[i-1] - nums[i]+1;
                moves += nums[i-1] - nums[i]+1;
			    nums[i] += moves2;
		}
	}
	return moves;

        
    }
};
