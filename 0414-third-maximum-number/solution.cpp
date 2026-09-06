// 414. Third Maximum Number
// https://leetcode.com/problems/third-maximum-number/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 13 MB
// Solved: 2025-09-28

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long firstmax = LONG_MIN;
        long secondmax = LONG_MIN;
        long thirdmax = LONG_MIN;

        for(auto num : nums){
            if(num == firstmax || num == secondmax || num == thirdmax){
                continue;
            }
            if(num > firstmax){
                thirdmax = secondmax;
                secondmax = firstmax; 
                firstmax = num;
            }
            else if(num > secondmax){
                thirdmax = secondmax ;
                secondmax = num ;

            }
            else if( num  > thirdmax){
                thirdmax = num;
            }

        }
        return (thirdmax == LONG_MIN) ? firstmax : thirdmax;
    }
};
