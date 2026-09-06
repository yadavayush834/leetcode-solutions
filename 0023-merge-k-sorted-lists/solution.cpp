// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/
// Difficulty: Hard | Language: cpp
// Runtime: 9 ms
// Memory: 18.5 MB
// Solved: 2026-04-19

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq(
            [](ListNode* a, ListNode* b) { return a->val > b->val; }
        );
        
        for (auto a : lists) {
            if (a) pq.push(a);
        }
        
        ListNode* h = new ListNode(0);
        ListNode* t = h;
        
        while (!pq.empty()) {
            ListNode* a = pq.top();
            pq.pop();
            
            t->next = a;
            t = t->next;
            
            if (a->next) pq.push(a->next);
        }
        
        return h->next;
    }
};
