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
    TreeNode* helper(TreeNode* cur,int val,int curDepth,int targetDepth) {
        if (cur == nullptr) return nullptr;
        
        if (curDepth+1 == targetDepth) {
            TreeNode *p = new TreeNode(val,nullptr,cur->right);
            cur->right = p;
            TreeNode *q = new TreeNode(val,cur->left,nullptr);
            cur->left = q;
        }
        
        cur->left = helper(cur->left,val,curDepth+1,targetDepth);
        cur->right = helper(cur->right,val,curDepth+1,targetDepth);
        
        return cur;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode(val,root,nullptr);
        return helper(root,val,1,depth);
    }
};