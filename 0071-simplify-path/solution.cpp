// 71. Simplify Path
// https://leetcode.com/problems/simplify-path/
// Difficulty: Medium | Language: cpp
// Runtime: 7 ms
// Memory: 14.9 MB
// Solved: 2026-02-05

class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st ; 
        string ans; 
        for(int i = 0 ; i< path.size() ; i++){
            if(path[i] == '/'){
                continue;
            }
            string t; 
            while(i<path.size() && path[i] != '/'){
                t += path[i];
                i++;
            }
            if(t == "."){
                continue;
            }
            else if(t == ".."){
                if(!st.empty()){
                    st.pop();
                }
                
            }
            else{
                st.push(t);
            }

        }
        while(!st.empty()){
            ans = "/"+st.top() +ans;
            st.pop();
        }
        if(ans.size() == 0){
            return "/";
        }
        return ans; 
    }
};
