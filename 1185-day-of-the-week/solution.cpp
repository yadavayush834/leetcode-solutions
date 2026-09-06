// 1185. Day of the Week
// https://leetcode.com/problems/day-of-the-week/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 7.8 MB
// Solved: 2026-04-18

class Solution {
public:
    string dayOfTheWeek(int d, int m, int y) {
        vector<string> a = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        
        vector<int> b = {31,28,31,30,31,30,31,31,30,31,30,31};
        
        int c = 0;
        
        for(int i = 1971; i < y; i++){
            if((i%4==0 && i%100!=0) || (i%400==0)) c += 366;
            else c += 365;
        }
        
        for(int i = 0; i < m-1; i++){
            c += b[i];
            if(i == 1 && ((y%4==0 && y%100!=0) || (y%400==0))) c++;
        }
        
        c += d;
        
        return a[(c + 4) % 7];
    }
};
