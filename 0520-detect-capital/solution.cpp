// 520. Detect Capital
// https://leetcode.com/problems/detect-capital/
// Difficulty: Easy | Language: cpp
// Runtime: 1 ms
// Memory: 8.2 MB
// Solved: 2025-08-25

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0 ;
        if(word.size() == 1){
            return true;
        }
        else{
            for(int i = 0 ; i< word.size() ; i++){
                if(isupper(word[i])){
                    count++;
                }
            }
            if(count == 1 && isupper(word[0])){
                return true;
            }
            else if(count == word.size()  || count == 0 ){
                return true;
            }
            else{
                return false;
            }
        }

        
    }
};
