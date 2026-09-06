/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = nullptr;
        ListNode* end = nullptr ;
        int carry = 0 ; 
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int sum = 0 ;
            sum += carry ;
            if(l1){
                sum += l1->val;
                l1 = l1->next; 

            }
            if(l2){
                sum += l2->val ;
                l2 = l2->next;
            }

            carry = sum /10 ; 
            ListNode* newnode = new ListNode(sum%10);

            if(l3 == nullptr){
                l3 = newnode;
                end = newnode;
            }
            else{
                end -> next = newnode;
                end = end -> next;
            }
        }
        return l3;

        
    }
};
