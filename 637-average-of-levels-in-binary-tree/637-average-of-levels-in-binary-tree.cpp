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
    void helper(vector<double>& ans,vector<int>& nodesLevel,TreeNode* cur,int level) {
        if (cur == NULL) return;
        else {
            if (nodesLevel.size() < level) {
                nodesLevel.push_back(0);
                ans.push_back(0);
            }
            nodesLevel[level-1]++;
            ans[level-1] = (ans[level-1]*(nodesLevel[level-1]-1) + cur->val)*1.0/nodesLevel[level-1];
            helper(ans,nodesLevel,cur->left,level+1);
            helper(ans,nodesLevel,cur->right,level+1);
        }
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        vector<int> nodesLevel;
        helper(ans,nodesLevel,root,1);
        return ans;
    }
};