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
    string helper(TreeNode* cur) {
        if (cur == nullptr) return "";
        
        if (cur->left == nullptr && cur->right == nullptr) return to_string(cur->val);
        
        if (cur->right == nullptr) return to_string(cur->val) + "(" + helper(cur->left) + ")";
        
        return to_string(cur->val) + "(" + helper(cur->left) + ")(" + helper(cur->right) + ")";
    }
public:
    string tree2str(TreeNode* root) {
        return helper(root);
    }
};