// 4024. Nearest Available Drone
// https://leetcode.com/problems/nearest-available-drone/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 55.2 MB
// Solved: 2026-08-16

class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = -1;
        int mini = INT_MAX;
        for(int i =0 ; i< drones.size(); i++){
            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];
            int dis = abs(x-target[0])+abs(y-target[1]);
            if(dis <= range){
                if(dis < mini){
                    mini = dis;
                    ans = i ;
                }
                else if(dis == mini){
                    ans = min(ans,i);
                }
                
            }
        }
        return ans;
    }
};
