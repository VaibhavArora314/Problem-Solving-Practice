class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        vector<int> dp(nums.size());
        
        dp[0] = nums[0];
        dp[1] = nums[1];
        
        for (int i=2;i<nums.size();i++) {
            dp[i] = max(dp[i-2],i>=3 ? dp[i-3] : 0)+nums[i];
        }
        
        return max(dp[nums.size()-1],dp[nums.size()-2]);
    }
};