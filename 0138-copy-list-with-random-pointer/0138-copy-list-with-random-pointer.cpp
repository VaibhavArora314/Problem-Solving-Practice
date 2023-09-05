/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *newHead=NULL,*last=NULL,*p=head;
        unordered_map<Node*,Node*> m;

        while (p) {
            Node *q = new Node(p->val);

            if (newHead == NULL) newHead = last = q;
            else {
                last->next = q;
                last = last->next;
            }

            m[p] = last;
            p=p->next;
        }
        
        p=head;
        while (p) {
            if (p->random) m[p]->random = m[p->random];
            p=p->next;
        }

        return newHead;
    }
};