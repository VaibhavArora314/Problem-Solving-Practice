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
    pair<int,int> helper(TreeNode* cur,int &ans) {
        if (cur == NULL) return {0,0};
        
        pair<int,int> x = helper(cur->left,ans), y = helper(cur->right,ans);
        int sum = x.first + y.first + cur->val, count = x.second + y.second + 1;

        if (sum/count == cur->val) ans++;
        cout<<cur->val<<" "<<sum<<" "<<count<<" "<<ans<<endl;

        return {sum,count};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        helper(root,ans);
        return ans;
    }
};