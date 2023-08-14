//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n) {
        int countOnes=0,curMax=0,maxAns=0;
        
        for (int i=0;i<n;i++) {
            if (a[i] == 1) {
                countOnes++;
                curMax--;
            } else {
                curMax++;
            }
            
            if (curMax < 0) curMax=0;
            maxAns = max(maxAns,curMax);
        }
        
        return countOnes + maxAns;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends