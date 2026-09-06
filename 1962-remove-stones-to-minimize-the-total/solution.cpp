#include <numeric>
#include <set>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        multiset<int> ms(piles.begin(), piles.end());

        while(k--){
            auto it = ms.end();
            --it;  
            
            int a = *it;
            int b = a - (a / 2);  
            
            ms.erase(it);
            ms.insert(b);
        }

        int sum = accumulate(ms.begin(), ms.end(), 0);
        return sum;
    }
};
