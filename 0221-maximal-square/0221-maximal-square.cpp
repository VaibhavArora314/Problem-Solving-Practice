class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;

        vector<vector<int>> dp(m,vector<int>(n,0));

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                dp[i][j] = matrix[i][j] - '0';
                if (dp[i][j]) ans = 1;
            }
        }

        for (int i = m-2;i>=0;i--) {
            for (int j = n-2;j>=0;j--) {
                if (dp[i][j] && dp[i+1][j] && dp[i][j+1] && dp[i+1][j+1])
                    dp[i][j] = 1+min(min(dp[i+1][j],dp[i][j+1]), dp[i+1][j+1]);
                ans = max(ans,dp[i][j]);
            }
        }

        return ans*ans;
    }
};
