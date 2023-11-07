class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid);

        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if (i == 0 && j == 0) continue;
                int temp = INT_MAX;
                if (i-1>=0) temp=min(temp,dp[i-1][j]);
                if (j-1>=0) temp=min(temp,dp[i][j-1]);
                dp[i][j] += (temp == INT_MAX ? 0 : temp);
            }
        }

        return dp.back().back();
    }
};