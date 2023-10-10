//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
    void helper(Node* cur,unordered_map<Node*,Node*> &pp,int target,vector<Node*> &tn) {
        if (cur == NULL) return;
        
        if (cur->data == target) tn.push_back(cur);
        
        if (cur->left) {
            pp[cur->left] = cur;
            helper(cur->left,pp,target,tn);
        }
        if (cur->right) {
            pp[cur->right] = cur;
            helper(cur->right,pp,target,tn);
        }
    }
    
    void nodesAtKDist(Node* cur,int k,unordered_map<Node*,Node*> &pp,Node* prev,vector<int> &ans) {
        if (cur == NULL) return;
        if (k == 0) {
            ans.push_back(cur->data);
            return;
        }
        
        if (pp.find(cur) != pp.end() && pp[cur] != prev) nodesAtKDist(pp[cur],k-1,pp,cur,ans);
        if (cur->left && cur->left != prev) nodesAtKDist(cur->left,k-1,pp,cur,ans);
        if (cur->right && cur->right != prev) nodesAtKDist(cur->right,k-1,pp,cur,ans);
    }
public:
    vector <int> KDistanceNodes(Node* root, int target , int k) {
        unordered_map<Node*,Node*> parentPointers;
        vector<Node*> targetNodes;
        helper(root,parentPointers,target,targetNodes);
        
        vector<int> ans;
        for (Node* t:targetNodes) {
            nodesAtKDist(t,k,parentPointers,NULL,ans);
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends