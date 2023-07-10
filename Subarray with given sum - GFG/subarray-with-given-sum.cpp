//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        long long l=0,r=0,slider=arr[0];
        if (s == arr[0]) return {1,1};
        
        for (int i=1;i<n;i++) {
            if (l>r) {
                slider = arr[i];
                l=r=i;
            } else {
                r++;
                slider += arr[r];
            }
            
            if (slider == s) return {l+1,r+1};
            while (slider > s && l<=r) {
                slider -= arr[l];
                l++;
            }
            if (slider == s && l<=r) return {l+1,r+1};
        }
        return {-1};
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends