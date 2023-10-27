class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> lps(n,vector<bool>(n,false));

        for (int i=0;i<n;i++) lps[i][i] = true;

        int maxLen = 1,startInd=0;
        
        for (int d=2;d<=n;d++) {
            for (int i=0;i+d-1<n;i++) {
                int j = i+d-1;

                if (d == 2)
                    lps[i][j] = (s[i] == s[j]);
                else if (s[i] == s[j])
                    lps[i][j] = lps[i+1][j-1];

                if (lps[i][j] && maxLen < j-i+1) {
                    maxLen = j-i+1;
                    startInd = i;
                }
            }
        }

        return s.substr(startInd,maxLen);
    }
};