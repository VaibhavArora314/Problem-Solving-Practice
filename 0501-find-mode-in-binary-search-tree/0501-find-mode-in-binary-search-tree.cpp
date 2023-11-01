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
    void getInorder(TreeNode* cur,vector<int>& inorder) {
        if (cur == NULL) return;

        getInorder(cur->left,inorder);
        inorder.push_back(cur->val);
        getInorder(cur->right,inorder);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> inorder;
        getInorder(root,inorder);

        vector<int> ans;
        int maxStreak=0,curStreak=0,curNum=-1;
        
        for (int num:inorder) {
            if (curNum == num) curStreak++;
            else {
                curNum = num;
                curStreak = 1;
            }

            if (curStreak > maxStreak) {
                ans = {curNum};
                maxStreak = curStreak;
            } else if (curStreak == maxStreak)
                ans.push_back(curNum);
        }

        return ans;
    }
};