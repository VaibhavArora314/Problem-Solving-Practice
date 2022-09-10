class Solution {
    void helper(vector<string>& ans, int n,int k,string s) {
        if (k == 0 && n==0) {
            ans.push_back(s);
            return;
        }
        
        if (k > 0) {
            if (n>0) {
                helper(ans,n-1,k+1,s+'(');
            }
            helper(ans,n,k-1,s+')');
        } else {
            helper(ans,n-1,k+1,s+'(');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans,n,0,"");
        return ans;
    }
};