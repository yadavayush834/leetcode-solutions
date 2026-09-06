// 860. Lemonade Change
// https://leetcode.com/problems/lemonade-change/
// Difficulty: Easy | Language: cpp
// Runtime: 3 ms
// Memory: 87.3 MB
// Solved: 2025-08-25

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0 ;
        int twenty = 0 ;
        for(int i = 0 ; i< bills.size();i++){
            if(bills[i] == 5){
                five++;
            }
            else if(bills[i] == 10){
                if(five){
                    ten++;
                    five--;
                }
                else{
                    return false;

                }
                
                
            }
            else{
                if(five >=1 && ten >= 1){
                    ten--;
                    five --;
                    twenty++;
                }
                else if(five >= 3){
                    five -=3;
                    twenty++;
                }
                
                else{
                    return false;
                }
            }

        }
        return true;
        
    }
};
