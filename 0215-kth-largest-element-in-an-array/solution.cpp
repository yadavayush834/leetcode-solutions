// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Difficulty: Medium | Language: cpp
// Runtime: 43 ms
// Memory: 61.7 MB
// Solved: 2026-01-26

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>q;

        // [3,2,1,5,6,4], k = 2
        // q -> empty 
        // q -   5 6

        for(int i : nums){
            q.push(i);
            if(q.size() > k){
                q.pop();
            }
        }
        return q.top();
    }
};
