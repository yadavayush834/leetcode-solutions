// 605. Can Place Flowers
// https://leetcode.com/problems/can-place-flowers/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 24.1 MB
// Solved: 2025-08-24

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;

        int i = 0;
        while(n && i < flowerbed.size()) {
            if(i == 0 && flowerbed[i] == 0 && (i+1 == flowerbed.size() || flowerbed[i+1] == 0)) {
                n--;
                flowerbed[i] = 1;  
            }
            else if(i == flowerbed.size() - 1 && flowerbed[i] == 0 && flowerbed[i-1] == 0) {
                n--;
                flowerbed[i] = 1;
            }
            else if(i > 0 && i < flowerbed.size() - 1 && flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                n--;
                flowerbed[i] = 1;
            }
            i++;
        }

        return n == 0;
    }
};
