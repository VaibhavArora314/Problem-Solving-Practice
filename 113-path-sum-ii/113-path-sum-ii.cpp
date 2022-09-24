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
    void helper(TreeNode* cur,int targetSum,int curSum,vector<vector<int>> &ans,vector<int> curPath) {
        if (cur == nullptr) return;
        
        curSum += cur->val;
        curPath.push_back(cur->val);
        
        if (cur->left == nullptr && cur->right == nullptr) {
            if (curSum == targetSum) ans.push_back(curPath);
            return;
        }
        
        helper(cur->left,targetSum,curSum,ans,curPath);
        helper(cur->right,targetSum,curSum,ans,curPath);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        helper(root,targetSum,0,ans,{});
        return ans;
    }
};