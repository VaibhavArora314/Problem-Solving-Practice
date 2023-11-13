class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        vector<long long> dp(n);
        for (int i=n-1;i>=0;i--) {
            dp[i] = questions[i][0];

            if (i + questions[i][1] + 1 < n) dp[i] += dp[i+questions[i][1]+1];

            if (i < n-1) dp[i] = max(dp[i],dp[i+1]);
        }

        return *max_element(dp.begin(),dp.end());
    }
};