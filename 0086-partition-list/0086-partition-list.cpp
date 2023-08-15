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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lh=NULL,*geh=NULL,*ll=NULL,*gel=NULL; // lh->less head,ll->less last,geh->greater equal head,gel->greater equal last

        ListNode* p = head,*q=NULL;
        while (p) {
            q=p;
            p=p->next;
            q->next = NULL;
            
            if (q->val < x) {
                if (lh == NULL) lh=ll=q;
                else {
                    ll->next=q;
                    ll=ll->next;
                }
            } else {
                if (geh == NULL) geh=gel=q;
                else {
                    gel->next=q;
                    gel=gel->next;
                }
            }
        }

        if (lh != NULL) {
            ll->next = geh;
            return lh;
        }

        return geh;
    }
};