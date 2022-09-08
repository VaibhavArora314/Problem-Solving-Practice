/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> nodes;
        TreeNode *cur = root;
        
        while (cur || !nodes.empty()) {
            if (cur == nullptr) {
                cur = nodes.top();
                nodes.pop();
                ans.push_back(cur->val);
                cur = cur->right;
            } else {
                nodes.push(cur);
                cur = cur->left;
            }
        }
        
        return ans;
    }
};