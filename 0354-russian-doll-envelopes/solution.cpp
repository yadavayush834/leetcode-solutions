// 354. Russian Doll Envelopes
// https://leetcode.com/problems/russian-doll-envelopes/
// Difficulty: Hard | Language: cpp
// Runtime: 35 ms
// Memory: 81.6 MB
// Solved: 2026-04-18

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](vector<int>& b, vector<int>& c){
            if(b[0]==c[0]) return b[1]>c[1];
            return b[0]<c[0];
        });
        
        int n=a.size();
        vector<int> d;
        
        for(int i=0;i<n;i++){
            int x=a[i][1];
            auto it=lower_bound(d.begin(), d.end(), x);
            if(it==d.end()) d.push_back(x);
            else *it=x;
        }
        
        return d.size();
    }
};
