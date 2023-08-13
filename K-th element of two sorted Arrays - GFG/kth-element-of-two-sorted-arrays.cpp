//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int leftPartitionSize = (n+m+1)/2;
        int low,high,mid1,mid2;
        high = (n>=k) ? k : n;
        low = (m>=k) ? 0 : k-m;
        
        while (low<=high) {
            mid1 = (low+high)/2;
            mid2 = k-mid1;
            
            int x1 = mid1 > 0 ? arr1[mid1-1] : INT_MIN,
                x2 = mid2 > 0 ? arr2[mid2-1] : INT_MIN,
                y1 = mid1 == n ? INT_MAX : arr1[mid1],
                y2 = mid2 == m ? INT_MAX : arr2[mid2];
            
            if (x1 <= y2 && x2 <= y1) return max(x1,x2);
            if (x1 > y2) high = mid1-1;
            else low = mid1+1;
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends