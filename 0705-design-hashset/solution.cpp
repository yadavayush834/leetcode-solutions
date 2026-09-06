// 705. Design HashSet
// https://leetcode.com/problems/design-hashset/
// Difficulty: Easy | Language: cpp
// Runtime: 9 ms
// Memory: 50.3 MB
// Solved: 2025-08-28

class MyHashSet {
public:
    vector<bool>hashset;
    MyHashSet() {
        hashset = vector<bool>(1000001,false);
        
    }
    
    void add(int key) {
        hashset[key] = true;
        
    }
    
    void remove(int key) {
        hashset[key] = false;
        
    }
    
    bool contains(int key) {
        if(hashset[key]){
            return true;
        }
        else{
            return false;
        }
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
