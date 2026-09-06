#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0 ;
        int profit = 0 ; 
        int  n = prices.size();
        for(int r =1 ; r< n ; r++){
            if(prices[r]>prices[l]){
                profit = max(profit,prices[r] - prices[l]);
            }
            else{
                l = r;
            }
        }
        return profit;
        
    }
};
