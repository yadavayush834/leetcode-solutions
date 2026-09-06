// 1979. Find Greatest Common Divisor of Array
// https://leetcode.com/problems/find-greatest-common-divisor-of-array/
// Difficulty: Easy | Language: cpp
// Runtime: 3 ms
// Memory: 16.2 MB
// Solved: 2025-10-09

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        int res = gcd(mini,maxi);
        return res; 
        
    }
};
