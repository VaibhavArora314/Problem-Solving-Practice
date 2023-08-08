//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

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

class Solution
{
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
    public:
    Node* addOne(Node *head) 
    {
        if (head == NULL) return new Node(1);
        
        head = reverse(head);
        
        Node*p=head,*q=NULL;
        int next=1;
        while (p && next>0) {
            p->data += next;
            next = (p->data>=10) ? 1 : 0;
            p->data %= 10;
            
            q=p;
            p = p->next;
        }
        if (p == NULL && next>0) q->next = new Node(next);
        
        return reverse(head);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends