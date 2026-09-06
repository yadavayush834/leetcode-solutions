// 190. Reverse Bits
// https://leetcode.com/problems/reverse-bits/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 8.7 MB
// Solved: 2025-08-25

class Solution {
public:
    string convert(uint32_t n) {
        string result = "";
        
        while (n > 0) {
            int bit = n % 2;
            result.push_back(bit + '0');
            n /= 2;
        }
        reverse(result.begin(), result.end());
       
        while (result.size() < 32) {
            result = '0' + result;
        }
        return result;
    }

    uint32_t binaryToDecimal(string binary) {
        uint32_t result = 0;
        for (char bit : binary) {
            result = result * 2 + (bit - '0');
        }
        return result;
    }

    uint32_t reverseBits(uint32_t n) {
        string t = convert(n);
        reverse(t.begin(), t.end()); 
        return binaryToDecimal(t);
    }
};
