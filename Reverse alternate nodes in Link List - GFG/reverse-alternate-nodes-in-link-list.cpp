//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    Node* reverse(Node* head) {
        if (!head || !head->next) return head;
        
        Node*p=NULL,*q=head,*r=head ? head->next : NULL;
        while (q) {
            q->next = p;
            p=q;
            q=r;
            if (r) r=r->next;
        }
        return p;
    }
    public:
    void rearrange(struct Node *odd)
    {
        if (!odd || !odd->next) return;
        
        Node* p = odd,*head=NULL,*last=NULL;
        while (p) {
            if (p->next) {
                if (!head)
                    head=last=p->next;
                else {
                    last->next=p->next;
                    last=last->next;
                }
                
                p->next = p->next->next;
                if (p->next) p=p->next;
                else {
                    last->next=NULL;
                    break;
                }
                
                last->next=NULL;
            } else
                break;
        }
        
        p->next = reverse(head);
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends