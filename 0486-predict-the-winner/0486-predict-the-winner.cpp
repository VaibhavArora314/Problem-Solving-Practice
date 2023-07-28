class Solution {
    int helper(vector<int>& nums,int i,int j,vector<vector<int>>& dp) {
        if (dp[i][j] != INT_MIN) return dp[i][j];
        if (i == j) {
            dp[i][j] = nums[i];
            return nums[i];
        }

        int maxDiffIfLeft = nums[i] - helper(nums,i+1,j,dp);
        int maxDiffIfRight = nums[j] - helper(nums,i,j-1,dp);

        dp[i][j] = max(maxDiffIfLeft,maxDiffIfRight);

        return dp[i][j];
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),INT_MIN));
        helper(nums,0,nums.size()-1,dp);
        return dp[0][nums.size()-1]>=0;
    }
};