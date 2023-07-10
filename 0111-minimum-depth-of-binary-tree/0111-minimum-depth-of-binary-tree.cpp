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
    int minDepth(TreeNode* cur) {
        if (cur == NULL) return 0;
        if (cur->left == NULL && cur->right == NULL) return 1;

        int m = 100000;
        if (cur->left != NULL) m = min(m,minDepth(cur->left));
        if (cur->right != NULL) m = min(m,minDepth(cur->right));

        // cout<<cur->val<<" "<<m+1<<endl;

        return m+1;
    }
};