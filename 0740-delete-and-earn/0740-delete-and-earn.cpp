class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> uniqueNums, occ, dp;

        int i=0;
        while (i < nums.size()) {
            int c=1;

            while (i + 1 < nums.size() && nums[i] == nums[i+1]) {
                c++;
                i++;
            }

            uniqueNums.push_back(nums[i]);
            occ.push_back(c);

            i++;
        }

        dp.resize(uniqueNums.size(),0);

        for (int i=0;i<dp.size();i++) {
            dp[i] = uniqueNums[i]*occ[i];

            int temp = 0;
            if (i-1 >= 0 && uniqueNums[i-1] != uniqueNums[i]-1) temp = max(temp,dp[i-1]);
            if (i-2 >= 0) temp = max(temp,dp[i-2]);
            if (i-3 >= 0) temp = max(temp,dp[i-3]);

            dp[i] += temp;
            // cout<<uniqueNums[i]<<" "<<dp[i]<<endl;
        }

        return *max_element(dp.begin(),dp.end());
    }
};