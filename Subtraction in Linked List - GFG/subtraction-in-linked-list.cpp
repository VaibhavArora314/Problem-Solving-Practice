//{ Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

Node* subLinkedList(Node* l1, Node* l2);

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
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends


/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

//You are required to complete this method

Node* reverse(Node* head) {
    if (head == NULL || head->next == NULL) return head;
    Node* p=NULL,*q=head,*r=head->next;
    while (q) {
        q->next=p;
        p=q;
        q=r;
        if (r) r= r->next;
    }
    return p;
}

int getLength(Node* head) {
    if (head == NULL) return 0;
    
    Node*p = head;int ans=1;
    while (p) {
        ans++;
        p=p->next;
    }
    return ans;
}

Node* subLinkedList(Node* l1, Node* l2)
{
    while (l1 && l1->data == 0) {
        l1=l1->next;
    }
    while (l2 && l2->data == 0) {
        l2 = l2->next;
    }
    
    if (l1 == NULL && l2 == NULL) return new Node(0);
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    Node* p=NULL,*q=NULL;
    int a = getLength(l1),b=getLength(l2);
    if (b>a) {
        p = l1;
        l1 = l2;
        l2 = p;
    } else if (b==a) {
        p=l1;q=l2;
        while (p && p->data == q->data) {
            p=p->next;
            q=q->next;
        }
        if (p == NULL) return new Node(0);
        if (p->data < q->data) {
            p = l1;
            l1 = l2;
            l2 = p;
        }
    }
    
    l1 = reverse(l1);
    l2 = reverse(l2);
    
    int prev=0,x;
    p=l1;q=l2;
    while (q) {
        x = p->data - q->data - prev;
        if (x < 0) {x+=10;prev=1;}
        else prev=0;
        
        p->data = x;
        
        p=p->next;
        q=q->next;
    }
    
    if (prev>0) {
        while (p && prev>0) {
            x = p->data - prev;
            if (x < 0) {x+=10;prev=1;}
            else prev=0;
            
            p->data = x;
            
            p=p->next;
        }
    }
    
    l1 = reverse(l1);
    while (l1 && l1->data == 0) {
        l1 = l1->next;
    }
    return l1;
}