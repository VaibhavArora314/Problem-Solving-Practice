//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node * zh=NULL,*oh=NULL,*th=NULL,*zl=NULL,*ol=NULL,*tl=NULL;
        
        while (head != NULL) {
            if (head->data == 0) {
                if (zh == NULL) zh = zl = head;
                else {
                    zl->next = head;
                    zl = zl->next;
                }
                
                head = head->next;
                zl->next = NULL;
            } else if (head->data == 1) {
                if (oh == NULL) oh = ol = head;
                else {
                    ol->next = head;
                    ol = ol->next;
                }
                
                head = head->next;
                ol->next = NULL;
            } else {
                if (th == NULL) th = tl = head;
                else {
                    tl->next = head;
                    tl = tl->next;
                }
                
                head = head->next;
                tl->next = NULL;
            }
        }
        
        if (zh != NULL) zl->next = oh;
        if (oh != NULL) ol->next = th;
        else if (zh != NULL) zl->next = th;
        
        return (zh != NULL ? zh : (oh != NULL ? oh : th));
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends