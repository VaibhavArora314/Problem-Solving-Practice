class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0,n=nums.size();
        for (int x:nums) sum += x;
        
        if (sum%2 != 0) return 0;
        
        vector<vector<int>> dp(n+1,vector<int>(sum/2+1));
        dp[0][0] = 1;

        for (int i=1;i<=n;i++) {
            if (nums[i-1] > sum/2) return 0;
            if (nums[i-1] == sum/2) return 1;
            
            for (int j=0;j<=sum/2;j++) {
                dp[i][j] = dp[i-1][j];
                
                if (j >= nums[i-1]) dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i][j];
            }
        }
        
        return dp[n][sum/2] > 0;
    }
};