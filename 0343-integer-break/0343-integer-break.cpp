class Solution {
    int helper(int nums,vector<int>& dp) {
        if (nums <= 3) nums;
        if (dp[nums] != 0) return dp[nums];

        int ans = nums;
        for (int i=2;i<nums;i++)
            ans = max(ans,i*helper(nums-i,dp));

        dp[nums] = ans;

        return ans;
    }
public:
    int integerBreak(int n) {
        if (n<=3) return n-1;
        vector<int> dp(n+1,0);
        return helper(n,dp);
    }
};