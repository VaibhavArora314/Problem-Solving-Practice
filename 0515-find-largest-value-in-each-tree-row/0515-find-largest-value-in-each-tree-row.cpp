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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};

        queue<pair<int,TreeNode*>> q;
        vector<int> ans;

        q.push({1,root});
        while (!q.empty()) {
            pair<int,TreeNode*> x = q.front();
            q.pop();

            if (x.first > ans.size()) ans.push_back(x.second->val);
            else ans[ans.size()-1] = max(ans.back(),x.second->val);

            if (x.second->left) q.push({x.first+1,x.second->left});
            if (x.second->right) q.push({x.first+1,x.second->right});
        }

        return ans;
    }
};