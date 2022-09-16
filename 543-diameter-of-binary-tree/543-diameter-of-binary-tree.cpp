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
    int helper(int &ans,TreeNode* cur) {
        if (cur == nullptr) return 0;
        
        int l = helper(ans,cur->left), r = helper(ans,cur->right);
        if (ans < l+r) ans = l+r;
        return (l>r ? l : r) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        helper(ans,root);
        return ans;
    }
};