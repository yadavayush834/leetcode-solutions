// 4025. Minimize the Maximum Waiting Time at Synchronized Traffic Lights
// https://leetcode.com/problems/minimize-the-maximum-waiting-time-at-synchronized-traffic-lights/
// Difficulty: Medium | Language: cpp
// Runtime: 3 ms
// Memory: 178.8 MB
// Solved: 2026-08-16

class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int wt = 0;

        

        int maxLight = *max_element(lights.begin(), lights.end());

        for (int i = 0; i < arrivalTime.size(); i++) {
            int r = arrivalTime[i] % period;

            if (r >= maxLight) {
                wt = max(wt, period - r);
            }
        }

        return wt;
    }
};
