// 1299. Replace Elements with Greatest Element on Right Side
// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
// Difficulty: Easy | Language: cpp
// Runtime: 4 ms
// Memory: 72.9 MB
// Solved: 2025-09-27

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxi = -1;
        
        
        for (int i = n - 1; i >= 0; i--) {
            int current = arr[i];
            arr[i] = maxi;
            maxi = max(maxi, current);
        }
        
        return arr;
    }
};
