//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        vector<int> minFromLeft;
        for (int i=0;i<n;i++) {
            if (minFromLeft.size() == 0 || arr[minFromLeft.back()] > arr[i]) 
                minFromLeft.push_back(i);
        }
        
        int j=n-1,k=minFromLeft.size()-1,ans=0;
        while (j>=0) {
            if (k>=0 && arr[minFromLeft[k]] <= arr[j]) {
                ans = max(ans,j-minFromLeft[k--]);
                continue;
            }
            j--;
        }
        
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends