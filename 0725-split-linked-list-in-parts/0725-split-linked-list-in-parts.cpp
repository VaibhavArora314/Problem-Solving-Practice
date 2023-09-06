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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        stack<ListNode*> stk;
        vector<ListNode*> ans;

        while (head) {
            stk.push(head);
            head = head->next;
        }

        while (k>0) {
            int x = stk.size()/k;

            if (x > 0) {
                ListNode* p = stk.top();
                p->next = NULL;

                while (x > 0 && !stk.empty()) {
                    p = stk.top();
                    stk.pop();

                    x--;
                }

                ans.push_back(p);
            } else {
                ans.push_back(NULL);
            }

            k--;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};