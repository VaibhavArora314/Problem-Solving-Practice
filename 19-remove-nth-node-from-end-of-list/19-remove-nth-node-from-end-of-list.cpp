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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        while (n-- && p) {
            p=p->next;
        }
        
        if (p == NULL) { // head is supposed to be deleted (size of LL == n)
            p = head;
            head = head->next;
            delete p;
            return head;
        }
        
        ListNode * q=head,*r = nullptr;
        while (p) {
            p=p->next;
            r = q;
            q=q->next;
        }
        r->next = q->next;
        delete q;
        
        return head;
    }
};