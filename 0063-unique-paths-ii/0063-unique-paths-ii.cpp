class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> dp(m,vector<int>(n,0));        
        dp[0][0] = 1;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (obstacleGrid[i][j] == 1) continue;

                if (j+1<n && obstacleGrid[i][j+1] == 0) dp[i][j+1] += dp[i][j];
                if (i+1<m && obstacleGrid[i+1][j] == 0) dp[i+1][j] += dp[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};