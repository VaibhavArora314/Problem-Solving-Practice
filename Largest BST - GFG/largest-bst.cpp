//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    // returns four values in vector
    // 1. is the subtree BST(1 or 0)
    // 2. smallest value of subtree
    // 3. largest valye of subtree
    // 4. size of subtree
    vector<int> helper(Node* cur,int &ans) {
        if (cur==NULL) return {1,0,0,0};
        if (cur->left == NULL && cur->right == NULL) return {1,cur->data,cur->data,1};
        
        vector<int> a = helper(cur->left,ans),b = helper(cur->right,ans);
        if (a[0] == 0 || b[0] == 0) return {0,0,0,0};
        
        vector<int> r = {0,0,0,0};
        if (a[3] > 0) {
            if (cur->data <= a[2]) return r;
            
            r[1] = a[1];
            r[3] = a[3];
        } else {
            r[1] = cur->data;
        }
        
        if (b[3] > 0) {
            if (cur->data >= b[1]) return r;
            
            r[2] = b[2];
            r[3] += b[3];
        } else {
            r[2] = cur->data;
        }
        
        r[0] = 1;
        r[3]++;
        if (ans < r[3]) ans = r[3];
        return r;
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        if (root == NULL) return 0;
        
    	int ans=1;
    	helper(root,ans);
    	return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends