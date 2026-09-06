// 3264. Final Array State After K Multiplication Operations I
// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/
// Difficulty: Easy | Language: cpp
// Runtime: 3 ms
// Memory: 27.8 MB
// Solved: 2026-02-11

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> st;

     
        for(int i = 0; i < nums.size(); i++) {
            st.push({nums[i], i});
        }

        while(k--) {
            auto top = st.top();
            st.pop();

            top.first *= multiplier;

            st.push(top);
        }

        while(!st.empty()) {
            auto top = st.top();
            st.pop();
            nums[top.second] = top.first;
        }

        return nums;
    }
};
