// 3591. Check if Any Element Has Prime Frequency
// https://leetcode.com/problems/check-if-any-element-has-prime-frequency/
// Difficulty: Easy | Language: cpp
// Runtime: 1 ms
// Memory: 24.5 MB
// Solved: 2026-04-16

class Solution {
public:
    bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    
        for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int>mp ; 
        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            if(isPrime(it->second)){
                return true;
            }
        }
        return false;

    }
};
