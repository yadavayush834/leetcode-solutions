// 492. Construct the Rectangle
// https://leetcode.com/problems/construct-the-rectangle/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8.1 MB
// Solved: 2025-08-25

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int>arr;
        long long int ans1 = 0;
        long long int ans2 = 0; 
        long long int w = 0 ;
        long long int l = 0;
        long long int mini = INT_MAX;
        long long int mini2 = INT_MAX;
        for(int i = 1  ; i*i <= area; i++){
            if(area % i == 0){
                w = min(area/i,i);
                l = max(area/i,i);
                mini = abs(l-w);
                if(mini < mini2){
                    ans1 = l;
                    ans2 = w;
                }
                

            }
        }
        arr.push_back(ans1);
        arr.push_back(ans2);
        return arr;
        
    }
};
