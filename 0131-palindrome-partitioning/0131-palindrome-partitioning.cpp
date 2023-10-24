class Solution {
    bool isPalindrome(string s,int i,int j) {
        while (i<j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    void helper(string s,int i,int j,vector<string> parts,vector<vector<string>>& ans) {
        if (isPalindrome(s,i,j)) {
            parts.push_back(s.substr(i,j-i+1));
            ans.push_back(parts);
            parts.pop_back();
        }

        for (int k=i;k<j;k++) {
            if (isPalindrome(s,i,k)) {
                parts.push_back(s.substr(i,k-i+1));
                helper(s,k+1,j,parts,ans);
                parts.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        helper(s,0,s.size()-1,{},ans);
        return ans;
    }
};