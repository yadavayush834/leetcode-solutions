// 3069. Distribute Elements Into Two Arrays I
// https://leetcode.com/problems/distribute-elements-into-two-arrays-i/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 23.9 MB
// Solved: 2026-08-20

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {

            int s1 = arr1.size();
            int s2 = arr2.size();

            if (arr1[s1 - 1] > arr2[s2 - 1]) {
                arr1.push_back(nums[i]);
            }
            else {
                arr2.push_back(nums[i]);
            }
        }

        for (int x : arr2) {
            arr1.push_back(x);
        }

        return arr1;
    }
};
