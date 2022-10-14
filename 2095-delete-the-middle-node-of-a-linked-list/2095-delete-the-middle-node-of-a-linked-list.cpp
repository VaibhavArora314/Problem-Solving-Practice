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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        
        ListNode *p=head,*q=head,*r=NULL;
        while (p && p->next) {
            r=q;
            q=q->next;
            p=p->next;
            if (p) p=p->next;
        }
        
        r->next = q->next;
        return head;
    }
};