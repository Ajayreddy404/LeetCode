/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr)    return nullptr;
        if(head->next==nullptr) return nullptr;
        ListNode* f = head;
        ListNode* s = head;
        bool ans = false;
        while(f->next!=nullptr && f->next->next!=nullptr && s->next!=nullptr){
            cout<<"here"<<endl;
            if(f->next->next == s->next){
                ans = true;
                break;
            }
            f = f->next->next;
            s = s->next;
        }
        cout<<ans<<" "<<s->val<<endl;
        if(!ans)    return nullptr;
        
        // return head;
        f = head;
        s = s->next;
        while(f!=s){
            f = f->next;
            s = s->next;
        }
        return f;
    }
};