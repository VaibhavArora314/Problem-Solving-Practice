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
    bool helper(TreeNode* cur, int targetSum, int curSum) {
        if (cur == nullptr) return false;
        if (cur->left == nullptr && cur->right == nullptr) return (curSum + cur->val == targetSum);
        
        return helper(cur->left,targetSum,curSum + cur->val) || helper(cur->right,targetSum,curSum + cur->val);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,targetSum,0);
    }
};