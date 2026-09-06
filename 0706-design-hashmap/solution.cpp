// 706. Design HashMap
// https://leetcode.com/problems/design-hashmap/
// Difficulty: Easy | Language: cpp
// Runtime: 86 ms
// Memory: 58.2 MB
// Solved: 2026-04-17

class MyHashMap {
public:
    vector<pair<int,int>> a;

    MyHashMap() {
        
    }
    
    void put(int k, int v) {
        for (auto &p : a) {
            if (p.first == k) {
                p.second = v;
                return;
            }
        }
        a.push_back({k, v});
    }
    
    int get(int k) {
        for (auto &p : a) {
            if (p.first == k) return p.second;
        }
        return -1;
    }
    
    void remove(int k) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i].first == k) {
                a.erase(a.begin() + i);
                return;
            }
        }
    }
};
