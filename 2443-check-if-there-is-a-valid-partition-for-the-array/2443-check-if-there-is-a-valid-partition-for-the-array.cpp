class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        for (int i=nums.size()-2;i>=0;i--) {
            if (i+2 == nums.size()) {
                if (nums[i] == nums[i+1])
                    dp[i] = 1;
                continue;
            }
            
            int a[3];
            for (int j=0;j<3;j++) {
                a[j] = nums[i+j];
            }

            if ((a[0] == a[1] && a[1] == a[2]) || (a[0] + 1 == a[1] && a[1] + 1 == a[2])) {
                if (i+3 < nums.size())
                    dp[i] = dp[i+3];
                else
                    dp[i] = 1;
            }

            if (a[0] == a[1] && dp[i] != 1)
                dp[i] = dp[i+2];
        }

        // for (auto x:dp) cout<<x<<" ";

        return dp[0];
    }
};