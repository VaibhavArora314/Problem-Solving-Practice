class Solution {
    int m = 1000000007;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        long long ans = 0;
        unordered_map<int,long long> dp;

        sort(arr.begin(),arr.end());

        for (int i=0;i<n;i++) {
            dp[arr[i]] = 1;
            for (int j=i-1;j>=0;j--) {
                if (arr[i]%arr[j] == 0)
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]]*dp[arr[i]/arr[j]])%m;
            }
            ans = (ans + dp[arr[i]])%m;
        }

        return ans;
    }
};