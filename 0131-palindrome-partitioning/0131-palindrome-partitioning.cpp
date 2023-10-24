class Solution {
    vector<vector<int>> m;
    bool isPalindrome(string s,int i,int j) {
        if (i == j) return true;
        if (m[i][j] != -1) return m[i][j] == 1;

        while (i<j){
            if (s[i] != s[j]) {
                m[i][j] = 0;
                return false;
            }
            i++;
            j--;
        }
        m[i][j] = 1;
        return true;
    }
    void helper(string s,int i,vector<string> parts,vector<vector<string>>& ans) {
        int j = s.size() - 1;
        
        if (isPalindrome(s,i,j)) {
            parts.push_back(s.substr(i,j-i+1));
            ans.push_back(parts);
            parts.pop_back();
        }

        for (int k=i;k<j;k++) {
            if (isPalindrome(s,i,k)) {
                parts.push_back(s.substr(i,k-i+1));
                helper(s,k+1,parts,ans);
                parts.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        m = vector<vector<int>>(s.size(),vector<int>(s.size(),-1));

        vector<vector<string>> ans;
        helper(s,0,{},ans);
        return ans;
    }
};