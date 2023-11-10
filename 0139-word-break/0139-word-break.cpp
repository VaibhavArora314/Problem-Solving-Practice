class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        unordered_set<string> words;
        for (auto w:wordDict) words.insert(w);
        if (words.find(s) != words.end()) return true;

        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for (int d=1;d<=n;d++) {
            for (int i=0;i<n-d+1;i++) {
                int j = i + d - 1;

                string sub = s.substr(i,d);

                if (words.find(sub) != words.end()) {
                    dp[i][j] = true;
                    continue;
                }

                for (int k=i;k<j;k++) {
                    if (dp[i][k] && dp[k+1][j]) {
                        dp[i][j] = true;
                        continue;
                    }
                }
            }
        }

        return dp[0][n-1];
    }
};