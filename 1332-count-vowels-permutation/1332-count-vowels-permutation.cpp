class Solution {
    int mod = 1000000007;
public:
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n,vector<long long>(5,1));

        for (int i=1;i<n;i++) {
            int x = 0;

            dp[i][0] = dp[i-1][1]%mod;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;
            for (int j=0;j<=4;j++) x = (x + (j == 2 ? 0 : dp[i-1][j]))%mod;
            dp[i][2] = x;
            dp[i][3] = (dp[i-1][2] + dp[i-1][4])%mod;
            dp[i][4] = dp[i-1][0]%mod;
        }

        // for (auto y:dp) {
        //     for (auto x:y) cout<<x<<" ";
        //     cout<<endl;
        // }

        int sum = 0;
        for (int i=0;i<=4;i++) sum = (sum + dp[n-1][i])%mod;
        return sum;
    }
};
