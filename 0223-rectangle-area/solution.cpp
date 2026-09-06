// 223. Rectangle Area
// https://leetcode.com/problems/rectangle-area/
// Difficulty: Medium | Language: cpp
// Runtime: 0 ms
// Memory: 10.6 MB
// Solved: 2025-09-22

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2-ax1)*(ay2-ay1);
        int area2 = (bx2 - bx1)*(by2-by1);

        int overlapx = max(0,min(ax2,bx2)-max(ax1,bx1));
        int overlapy = max(0,min(ay2,by2)-max(ay1,by1));
        int overlaparea= overlapx * overlapy;
        return area1 + area2 - overlaparea;
        
    }
};
