//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int r=0,c=0;
 		while (k>0 && r<n && c<m) {
 		    for (int i=c;i<m;i++) {
 		        k--;
 		        if (k == 0) return a[r][i];
 		    }
 		    r++;
 		    
 		    for (int i=r;i<n;i++) {
 		        k--;
 		        if (k == 0) return a[i][m-1];
 		    }
 		    m--;
 		    
 		    for (int i=m-1;i>=c;i--) {
 		        k--;
 		        if (k==0) return a[n-1][i];
 		    }
 		    n--;
 		    
 		    for (int i=n-1;i>=r;i--) {
 		        k--;
 		        if (k == 0) return a[i][c];
 		    }
 		    c++;
 		}
 		
 		return a[r][c];
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends