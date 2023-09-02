class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict;
        for (string x:dictionary) dict.insert(x);

        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for (int k=0;k<n;k++) {
            int i,j;
            for (i=0,j=0+k;j<n;i++,j++) {
                if (dict.find(s.substr(i,j-i+1)) != dict.end()) {
                    dp[i][j] = 0;
                    continue;
                }

                dp[i][j] = j-i+1;

                for (int x=i;x<j;x++) {
                    if (dp[i][x] + dp[x+1][j] < dp[i][j]) {
                        dp[i][j] = dp[i][x]+dp[x+1][j];
                        if (dp[i][j] == 0) break;
                    }
                }
            }
        }

        // for (auto x:dp) {
        //     for (auto y:x) cout<<y<<" ";
        //     cout<<endl;
        // }

        return dp[0][n-1];
    }
};