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
    bool helper(TreeNode * cur1, TreeNode * cur2) {
        if (cur1 == nullptr && cur2 == nullptr) return true;
        if (cur1 == nullptr || cur2 == nullptr) return false;
        
        if (cur1->val != cur2->val) return false;
        return helper(cur1->left,cur2->right) && helper(cur1->right,cur2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root->left,root->right);
    }
};