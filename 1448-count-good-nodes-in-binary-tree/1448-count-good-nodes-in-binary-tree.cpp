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
    void helper(int &ans, TreeNode* cur,int max) {
        if (cur == NULL) return;
        if (cur-> val >= max) {
            ans++;
            max = cur->val;
        } 
        helper(ans,cur->left,max);
        helper(ans,cur->right,max);
    }
public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans  = 1;
        helper(ans,root->left,root->val);
        helper(ans,root->right,root->val);
        return ans;
    }
};