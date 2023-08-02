//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        vector<vector<int>> cost(n+1,vector<int>(n+1,0));
        
        for (int d=1;d<=n;d++) {
            for (int i=0;i<=n-d;i++) {
                int j=i+d,m = INT_MAX,w=0;
                for (int k=i;k<j;k++) {
                    w += freq[k];
                    m = min(m,cost[i][k]+cost[k+1][j]);
                }
                cost[i][j] = m+w;
            }
        }
        
        return cost[0][n];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends