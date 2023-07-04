//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        long long ans=0,i=0,prev=1,l=-1,r=-1;
        
        while (i<n) {
            if (arr[i] >= k) {prev=1;l=-1;r=-1;}
            else {
                ans++;
                if (l < 0) {
                    prev = arr[i];
                    l=i;r=i;
                } else {
                    while (prev*arr[i] >= k && l<=r) {
                        prev /= arr[l];
                        l++;
                    }
                    if (l>r) {
                        prev = arr[i];l=i;r=i;
                    } else {
                        ans += r-l+1;
                        prev*=arr[i];
                        r = i;
                    }
                }
            }
            i++;
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
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends