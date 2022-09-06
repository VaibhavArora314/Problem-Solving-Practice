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
    TreeNode* helper(TreeNode* cur) {
        if (cur == NULL) return NULL;
        
        cur->left = helper(cur->left);
        cur-> right = helper(cur->right);
        
        if (cur->val == 0 && cur->left == NULL && cur->right == NULL) {
            return NULL;
        }
        
        return cur;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        return helper(root);
    }
};