// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// Difficulty: Hard | Language: cpp
// Runtime: 0 ms
// Memory: 95.1 MB
// Solved: 2026-04-18

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size() > b.size()) return findMedianSortedArrays(b, a);

        int m = a.size(), n = b.size();
        int l = 0, r = m;

        while(l <= r) {
            int i = (l + r) / 2;
            int j = (m + n + 1) / 2 - i;

            int a1 = (i == 0) ? INT_MIN : a[i - 1];
            int a2 = (i == m) ? INT_MAX : a[i];
            int b1 = (j == 0) ? INT_MIN : b[j - 1];
            int b2 = (j == n) ? INT_MAX : b[j];

            if(a1 <= b2 && b1 <= a2) {
                if((m + n) % 2 == 0)
                    return (max(a1, b1) + min(a2, b2)) / 2.0;
                else
                    return max(a1, b1);
            }
            else if(a1 > b2) {
                r = i - 1;
            }
            else {
                l = i + 1;
            }
        }
        return 0.0;
    }
};
