//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int> rowSum(n,0),colSum(n,0);
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                rowSum[i] += matrix[i][j];
                colSum[j] += matrix[i][j];
            }
        }
            
        int maxRow=*max_element(rowSum.begin(),rowSum.end()),maxCol=*max_element(colSum.begin(),colSum.end());
        
        int rowAdd=0,colAdd=0;
        for (int i=0;i<n;i++) {
            rowAdd += maxRow - rowSum[i];
            colAdd += maxCol - colSum[i];
        }
            
        return max(rowAdd,colAdd);
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
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends