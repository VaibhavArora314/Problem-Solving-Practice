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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> levOrd;
		if (!root) return levOrd;
		else {
			TreeNode* cur = NULL;
			pair<TreeNode*,int> temp;
			levOrd.push_back(vector<int>(1,root->val));
			deque<pair<TreeNode*,int>> q;
			if (root->left) q.push_back(pair<TreeNode*,int>(root->left,1));
			if (root->right) q.push_back(pair<TreeNode*,int>(root->right,1));
			while (!q.empty()) {
				temp = q.front();
				cur = temp.first;
				if (cur->left) q.push_back(pair<TreeNode*,int>(cur->left,temp.second+1));
				if (cur->right) q.push_back(pair<TreeNode*,int>(cur->right,temp.second+1));
				if (levOrd.size() == temp.second) levOrd.push_back(vector<int>(0,0));
				levOrd[temp.second].push_back(temp.first->val);
				q.pop_front();
			}
		}
		return levOrd;
	}
};