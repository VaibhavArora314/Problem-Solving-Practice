class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i=0,j=1;
        vector<string> ans;
        while (i<target.size() && j<=n) {
            ans.push_back("Push");
            if (j != target[i]) ans.push_back("Pop");
            else i++;

            j++;
        }
        return ans;
    }
};