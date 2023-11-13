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
        ListNode* head = l1;
        int rem = 0, cur = 0;
        while(l1->next != nullptr && l2->next!=nullptr){
            cur = l1->val + l2->val + rem;
            l1->val = cur%10;
            rem = cur/10;
            l1 = l1->next;
            l2 = l2->next;
        }

        cur = l1->val + l2->val +rem;
        l1->val = cur%10;
        rem = cur/10;
        // cout<<rem<<endl;
        if(l1->next==nullptr){
            
            l2 = l2->next;

            while(l2 != nullptr){
                ListNode* node = new ListNode();
                cur = l2->val + rem;
                node->val = cur%10;
                rem = cur/10;
                l1->next = node;
                l1 = l1->next;
                l2 = l2->next;
            }

        }else{

            while(l1->next != nullptr){
                l1 = l1->next;
                cur = l1->val + rem;
                l1->val = cur%10;
                rem = cur/10;
            }
            
        }
        // cout<<rem<<endl;
        if(rem){
            ListNode* node = new ListNode();
            node->val = rem;
            l1->next = node;
        }

        return head;
    }
};