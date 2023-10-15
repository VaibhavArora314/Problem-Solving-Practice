class Solution {
    int MOD = 1000000007;
public:
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps+1,vector<int>(min(steps+1,arrLen),0));
        dp[0][0] = 1;

        for (int i=0;i<steps;i++) {
            for (int j=0;j<=min(i,arrLen-1);j++) {
                if (j > 0) dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j])%MOD;
                dp[i+1][j] = (dp[i+1][j] + dp[i][j])%MOD;
                if (j < arrLen-1) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j])%MOD;
            }
        }

        // for (auto x:dp) {
        //     for (auto y:x)
        //         cout<<y<<" ";
        //     cout<<endl;
        // }

        return dp[steps][0];
    }
};