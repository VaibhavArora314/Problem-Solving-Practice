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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        
        ListNode*l=head,*lb=NULL;

        for (int i=1;l && i<left;i++) {
            lb = l;
            l = l->next;
        }

        ListNode* q = NULL,*p=l,*r=l->next;
        for (int i=0;i<=right-left;i++) {
            p->next=q;
            q=p;
            p=r;
            if (r) r=r->next;
        }

        l->next = p;
        if (lb) {
            lb->next = q;
            return head;
        }
        return q;
    }
};