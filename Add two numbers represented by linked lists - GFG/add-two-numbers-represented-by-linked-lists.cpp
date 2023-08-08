//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    struct Node* reverse(struct Node* head) {
        if (head == NULL || head->next == NULL) return head;
        struct Node* p=NULL,*q=head,*r=head->next;
        while (q) {
            q->next=p;
            p=q;
            q=r;
            if (r) r= r->next;
        }
        return p;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverse(first);
        second = reverse(second);
        
        struct Node* third=NULL,*p=NULL;
        int carry=0,x;
        while (first && second) {
            x=first->data + second->data+carry;
            if (x>=10) {carry = 1; x%=10;}
            else carry=0;
            
            if (third == NULL) third = p = new struct Node(x);
            else {p->next = new struct Node(x);p=p->next;}
            
            first = first->next;
            second = second->next;
        }
        
        while (first) {
            x=first->data+carry;
            if (x>=10) {carry = 1; x%=10;}
            else carry=0;
            
            if (third == NULL) third = p = new struct Node(x);
            else {p->next = new struct Node(x);p=p->next;}
            
            first = first->next;
        }
        
        while (second) {
            x=second->data+carry;
            if (x>=10) {carry = 1; x%=10;}
            else carry=0;
            
            if (third == NULL) third = p = new struct Node(x);
            else {p->next = new struct Node(x);p=p->next;}
            
            second = second->next;
        }
        
        if (carry>0) p->next = new struct Node(carry);
        
        return reverse(third);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends