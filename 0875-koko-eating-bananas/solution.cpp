// 875. Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas/
// Difficulty: Medium | Language: cpp
// Runtime: 14 ms
// Memory: 22.9 MB
// Solved: 2026-02-01

class Solution {
public:
    long long hours(vector<int>& piles, int speed){
        long long ans = 0; 
        for (int i : piles) {
            ans += ( (long long)i + speed - 1 ) / speed;
        }
        return ans; 
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());
        int high = maxi;
        int low = 1;
        int s = maxi;

        while (low <= high) {
            int mid = low + (high - low) / 2;  
            long long a = hours(piles, mid);  

            if (a <= h) {
                s = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return s;
    }
};
