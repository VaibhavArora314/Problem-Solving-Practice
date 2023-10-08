class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),INT_MIN));

        int ans=INT_MIN;
        for (int i=nums1.size()-1;i>=0;i--) {
            for (int j=nums2.size()-1;j>=0;j--) {
                if (j+1<nums2.size() && dp[i][j+1] > dp[i][j]) dp[i][j] = dp[i][j+1];
                if (i+1<nums1.size() && dp[i+1][j] > dp[i][j]) dp[i][j] = dp[i+1][j];

                int temp = nums1[i]*nums2[j];
                if (i+1<nums1.size() && j+1<nums2.size() && dp[i+1][j+1] > 0) temp += dp[i+1][j+1];
                if (temp > dp[i][j]) dp[i][j] = temp;

                ans = max(ans,dp[i][j]);
            }
        }

        for (auto x:dp) {
            for (auto y:x) {
                cout<<y<<" ";
            }
            cout<<endl;
        }

        return ans;
    }
};