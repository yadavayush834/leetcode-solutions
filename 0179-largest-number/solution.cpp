// 179. Largest Number
// https://leetcode.com/problems/largest-number/
// Difficulty: Medium | Language: cpp
// Runtime: 7 ms
// Memory: 16.9 MB
// Solved: 2026-08-17

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>st;
        bool f = false;
        for(int i =0 ; i< nums.size(); i++){
            if(nums[i] != 0){
                f = true;
            }
            
        }
        if(!f){
            return "0"; 
        }
        for(int i = 0 ; i< nums.size() ; i++){
            st.push_back(to_string(nums[i]));
        }

        sort(st.begin(),st.end(), [](string a, string b){
            return a+b > b+a ; 
        });


        string ans = "";
        for(int i =0 ; i< st.size(); i++){
            ans += st[i];
        } 
        return ans; 
    }
};
