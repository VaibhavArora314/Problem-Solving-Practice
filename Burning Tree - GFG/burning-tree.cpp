//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    void generateParentPointers(Node* cur,unordered_map<Node*,Node*>& m) {
        if (cur == NULL) return;
        
        if (cur->left) {
            m[cur->left] = cur;
            generateParentPointers(cur->left,m);
        }
        
        if (cur->right) {
            m[cur->right] = cur;
            generateParentPointers(cur->right,m);
        }
    }
    int bfs(queue<Node*> &q,unordered_set<int> &visited,unordered_map<Node*,Node*>& pp) {
        if (q.empty()) return 0;
        
        queue<Node*> nextQ;
        while (!q.empty()) {
            Node*p = q.front();
            q.pop();
            
            if (p->left && visited.find(p->left->data) == visited.end()) {
                nextQ.push(p->left);
                visited.insert(p->left->data);
            }
            if (p->right && visited.find(p->right->data) == visited.end()) {
                nextQ.push(p->right);
                visited.insert(p->right->data);
            }
            if (pp.find(p) != pp.end() && visited.find(pp[p]->data) == visited.end()) {
                nextQ.push(pp[p]);
                visited.insert(pp[p]->data);
            }
        }
        
        return bfs(nextQ,visited,pp)+1;
    }
    void findTarget(Node*cur,int target,Node* &t) {
        if (cur==NULL || t != NULL) return;
        
        if (cur->data == target) t = cur;
        
        findTarget(cur->left,target,t);
        findTarget(cur->right,target,t);
    }
  public:
    int minTime(Node* root, int target) {
        unordered_map<Node*,Node*> parentPointers;
        generateParentPointers(root,parentPointers);
        
        Node* t=NULL;
        findTarget(root,target,t);
        
        queue<Node*> q;
        q.push(t);
        
        unordered_set<int> visited;
        visited.insert(t->data);
        
        return bfs(q,visited,parentPointers)-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends