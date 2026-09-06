// 151. Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/
// Difficulty: Medium | Language: cpp
// Runtime: 4 ms
// Memory: 10.9 MB
// Solved: 2026-08-15

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        vector<string>st;
        string t = "";
        for(int i =0 ; i<s.size(); i++){
            if(s[i] != ' '){
                t += s[i];
            }
            else{
                if(t != ""){
                    st.push_back(t);
                    t = "";
                }
            }
        }
       if(t != "")
            st.push_back(t);

        for(int i = st.size()-1; i >= 0 ; i--){
            ans += st[i];
            if(i != 0){
                ans += " ";
            }
        }
        return ans;
        
    }
};
