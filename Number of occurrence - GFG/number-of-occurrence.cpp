//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    int binSearch(int arr[],int n,int target) {
        int low = 0, high = n-1, mid;
        
        while (low<high) {
            mid = (low+high)/2;
            if (arr[mid] < target) low = mid+1;
            else high = mid;
        }
        
        return low;
    }
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int start = binSearch(arr,n,x);
	    if (arr[start] != x) return 0;
	    if (arr[n-1] == x) return n-start;
	    
	    return binSearch(arr,n,x+1)-start;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends