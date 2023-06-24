//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        if (n <= 1) return 0;
        
        sort(arr,arr+n);
        int minDiff = arr[n-1] - arr[0],tempMin = arr[0]+k,tempMax=arr[n-1]-k;
        
        for (int i=0;i<n-1;i++) {
            if (arr[i+1]-k < 0) continue;
            
            tempMin = min(arr[0]+k,arr[i+1]-k);
            tempMax = max(arr[n-1]-k,arr[i]+k);
            
            minDiff = min(minDiff,tempMax-tempMin);
        }
        
        return minDiff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends