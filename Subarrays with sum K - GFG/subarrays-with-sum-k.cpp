//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int arr[], int n, int k)
    {
        unordered_map<int,int> m;
        m[0] = 1;
        
        int ans=0,total=0;
        for(int i=0;i<n;i++) {
            total += arr[i];

            if (m[total-k] > 0) ans+=m[total-k];
            
            m[total]++;
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
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends