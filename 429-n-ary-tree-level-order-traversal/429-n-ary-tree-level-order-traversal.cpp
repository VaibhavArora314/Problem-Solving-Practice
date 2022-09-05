/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == NULL) return {};
        
        vector<vector<int>> ans;
        deque<pair<int,Node*>> q;
        q.push_back({1,root});
        pair<int,Node *> temp;
        Node *cur = NULL;
        
        while (!q.empty()) {
            temp = q.front();
            cur = temp.second;
            if (ans.size() < temp.first) {
                ans.push_back(vector<int>(0));
            }
            ans[temp.first-1].push_back(cur->val);
            for (auto x:cur->children) {
                if (x != NULL)  q.push_back({temp.first+1,x});
            }
            q.pop_front();
        }
        
        return ans;
    }
};