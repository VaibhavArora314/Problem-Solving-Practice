//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    int helper(string A,string revA,int i,int j,vector<vector<int>> &dp) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (A[i] == revA[j]) dp[i][j] = 1 + helper(A,revA,i-1,j-1,dp);
        else dp[i][j] = max(helper(A,revA,i-1,j,dp),helper(A,revA,i,j-1,dp));
        
        return dp[i][j];
    }
  public:
    int longestPalinSubseq(string A) {
        int n=A.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        string revA = A;
        reverse(revA.begin(),revA.end());
        
        return helper(A,revA,n-1,n-1,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends