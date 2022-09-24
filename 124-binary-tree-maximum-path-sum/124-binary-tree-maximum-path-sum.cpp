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
    int helper(int& m, TreeNode* cur) {
        if (cur == nullptr) return -1001;
        
        int l,r;
        l = helper(m,cur->left);
        r = helper(m,cur->right);
        
        m = max(m,cur->val);
        m = max(m,l + (cur->val>0 ? cur->val : 0));
        m = max(m,r + (cur->val>0 ? cur->val : 0));
        m = max(m,l+r+cur->val);
        
        return max(max(l,r),0)+cur->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int m = root ? root->val : 0;
        int x = helper(m,root);
        return m;
    }
};