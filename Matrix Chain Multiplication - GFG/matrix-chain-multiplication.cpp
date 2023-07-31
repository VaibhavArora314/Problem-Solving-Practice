//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> cost(N,vector<int>(N,0));
        
        for (int d=1;d<N-1;d++) {
            for (int i=1;i<N-d;i++) {
                int j = i+d, minCost = INT_MAX,temp;
                for (int k=i;k<j;k++) {
                    temp = cost[i][k] + cost[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    minCost = min(temp,minCost);
                }
                cost[i][j] = minCost;
            }
        }
        
        return cost[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends