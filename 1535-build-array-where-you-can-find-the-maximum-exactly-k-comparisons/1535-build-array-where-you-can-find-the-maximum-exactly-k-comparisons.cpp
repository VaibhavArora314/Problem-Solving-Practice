class Solution {
    int MOD = 1000000007;
    int helper(int i,int maxSoFar,int remain,int n,int m,vector<vector<vector<int>>> &dp) {
        if (i == n) return remain == 0;
        if (remain < 0) return 0;
        if (dp[i][maxSoFar][remain] != -1) return dp[i][maxSoFar][remain];

        int ans = 0;

        for (int num = 1; num <= maxSoFar; num++)
            ans = (ans + helper(i+1,maxSoFar,remain,n,m,dp))%MOD;

        for (int num=maxSoFar+1;num<=m;num++)
            ans = (ans+helper(i+1,num,remain-1,n,m,dp))%MOD;
        
        dp[i][maxSoFar][remain] = ans;

        return ans;
    }
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return helper(0,0,k,n,m,dp);
    }
};