class Solution {
    bool helper(int i, vector<int>& leftChild, vector<int>& rightChild, vector<int>& visited) {
        if (visited[i]) return false;
        visited[i] = true;

        bool ans = true;
        if (leftChild[i] != -1) ans = ans && helper(leftChild[i],leftChild,rightChild,visited);
        if (ans && rightChild[i] != -1) ans = ans && helper(rightChild[i],leftChild,rightChild,visited);

        return ans;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parents(n,0);
        for (int l:leftChild) {
            if (l == -1) continue;

            if (parents[l] == 1) return false;
            parents[l] = 1;
        }

        for (int r:rightChild) {
            if (r == -1) continue;

            if (parents[r] == 1) return false;
            parents[r] = 1;
        }

        int root = -1;
        for (int i=0;i<n;i++) {
            if (parents[i] == 0) {
                if (root != -1) return false;
                root = i;
            }
        }
        if (root == -1) return false;

        vector<int> visited(n,0);
        bool ans = helper(root,leftChild,rightChild,visited);
        if (!ans) return false;

        for (int v:visited) {
            if (v == 0)
                return false;
        }
        return true;
    }
};