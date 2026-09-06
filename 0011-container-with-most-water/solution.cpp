// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/
// Difficulty: Medium | Language: cpp
// Runtime: 3 ms
// Memory: 62.9 MB
// Solved: 2025-08-31

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0; 
        int j = height.size() - 1;
        int maxi = 0;
        
        while (i < j) {
            int length = j - i;
            int heights = min(height[i], height[j]);
            int area = length * heights;
            maxi = max(maxi, area);

            
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxi;
    }
};
