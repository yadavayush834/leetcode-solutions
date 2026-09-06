// 496. Next Greater Element I
// https://leetcode.com/problems/next-greater-element-i/
// Difficulty: Easy | Language: cpp
// Runtime: 3 ms
// Memory: 12.8 MB
// Solved: 2025-10-03

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        stack<int>st;

        for(int i = nums2.size()-1 ; i >= 0 ; i--){
            int num = nums2[i];

            while(!st.empty() && st.top() <= num){
                st.pop();
            }
            mpp[num] = st.empty() ? -1 : st.top();
            st.push(num);
        }
        vector<int>result;
        for(int nums : nums1){
            result.push_back(mpp[nums]);
        }
        return result;
        
    }
};
