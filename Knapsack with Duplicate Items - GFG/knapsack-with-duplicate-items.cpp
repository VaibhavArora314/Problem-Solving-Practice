//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N+1,vector<int>(W+1,0));
        
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=W;j++) {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if (j >= wt[i-1]) {
                    dp[i][j] = max(dp[i-1][j-wt[i-1]]+val[i-1],dp[i][j]);
                    dp[i][j] = max(dp[i][j-wt[i-1]]+val[i-1],dp[i][j]);
                }
            }
        }
        
        // for (auto y:dp) {
        //     for (auto x:y) cout<<x<<" ";
        //     cout<<endl;
        // }
        
        return dp[N][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends