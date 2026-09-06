// 506. Relative Ranks
// https://leetcode.com/problems/relative-ranks/
// Difficulty: Easy | Language: cpp
// Runtime: 0 ms
// Memory: 15.4 MB
// Solved: 2025-09-28

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size() ;
        priority_queue<pair<int,int>>pq ;
        for(int i =0 ; i <n ; i++){ 
            pq.push({score[i], i});
        }
        int rank = 1; 
        vector<string>result(n); 
        vector<string>medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        while(!pq.empty()){
            int index = pq.top().second;
            pq.pop(); 
            if(rank <= 3){ 
                result[index] = medals[rank-1];
            }
            else{ 
                result[index] = to_string(rank);
            }
            rank++ ;
        }
        return result;
        
    }
};
