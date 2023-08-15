//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int missingNumber(vector<int>& a, int n) {
        a.push_back(0);
        
        int i=0;
        while (i<n) {
            while (a[i] != 0 && a[i] != i+1) {
                swap(a[i],a[a[i]-1]);
            }
            i++;
        }
        
        for (int i=0;i<n;i++) {
            if (a[i] == 0) return i+1;
        }
        
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends