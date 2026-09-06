// 68. Text Justification
// https://leetcode.com/problems/text-justification/
// Difficulty: Hard | Language: cpp
// Runtime: 0 ms
// Memory: 10.7 MB
// Solved: 2026-04-18

class Solution {
public:
    vector<string> fullJustify(vector<string>& w, int m) {
        vector<string> res;
        int n = w.size();

        int i = 0;
        while (i < n) {
            int j = i;
            int len = 0;

            while (j < n && len + w[j].size() + (j - i) <= m) {
                len += w[j].size();
                j++;
            }

            int words = j - i;
            int spaces = m - len;
            string line = "";

            if (j == n) {
                for (int k = i; k < j; k++) {
                    line += w[k];
                    if (k != j - 1) {
                        line += " ";
                        spaces--;
                    }
                }
                line += string(spaces, ' ');
            } 
            else if (words == 1) {
                line += w[i];
                line += string(m - w[i].size(), ' ');
            } 
            else {
                int gap = spaces / (words - 1);
                int extra = spaces % (words - 1);

                for (int k = i; k < j; k++) {
                    line += w[k];
                    if (k != j - 1) {
                        line += string(gap, ' ');
                        if (extra > 0) {
                            line += " ";
                            extra--;
                        }
                    }
                }
            }

            res.push_back(line);
            i = j;
        }

        return res;
    }
};
