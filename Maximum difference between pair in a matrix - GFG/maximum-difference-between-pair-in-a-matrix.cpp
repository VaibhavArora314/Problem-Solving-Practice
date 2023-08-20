//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findMaxValue(vector<vector<int>>&mat, int N){
        vector<vector<int>> mx(mat),mn(mat);
        int ans=INT_MIN;
        
        for (int i=N-1;i>=0;i--) {
            for (int j=N-1;j>=0;j--) {
                if (i < N-1)
                    mx[i][j] = max(mx[i][j],mx[i+1][j]);
                if (j<N-1)
                    mx[i][j] = max(mx[i][j],mx[i][j+1]);
            }
        }
        
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                if (i > 0)
                    mn[i][j] = min(mn[i][j],mn[i-1][j]);
                if (j > 0)
                    mn[i][j] = min(mn[i][j],mn[i][j-1]);
                
                if (i<N-1 && j<N-1) ans = max(ans,mx[i+1][j+1]-mn[i][j]);
            }
        }
        
        return ans;
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
	    vector<vector<int>>mat(n,vector<int>(n, 0));
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            cin >> mat[i][j];
	        }
	    }
	    Solution ob;
	    int ans = ob.findMaxValue(mat, n);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends