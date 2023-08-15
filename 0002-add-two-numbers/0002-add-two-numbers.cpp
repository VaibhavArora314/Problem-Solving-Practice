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
        ListNode* head=NULL,*last=NULL;
        int prev=0;
        
        if (l1 == NULL && l2 == NULL) return new ListNode(0);

        while (l1 && l2) {
            int x = l1->val + l2->val + prev;
            prev = x/10;
            x=x%10;

            ListNode *p = new ListNode(x);
            if (!head) head = last = p;
            else {
                last->next= p;
                last = last->next;
            }

            l1=l1->next;
            l2=l2->next;
        }

        ListNode * r = (l1 == NULL) ? l2 : l1;

        while (r) {
            int x=r->val+prev;
            prev = x/10;
            x = x%10;

            ListNode *p = new ListNode(x);
            if (!head) head = last = p;
            else {
                last->next= p;
                last = last->next;
            }

            r=r->next;
        }

        if (prev > 0) last->next = new ListNode(prev);

        return head;
    }
};