//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    bool isPossible(int A[],int N,int M,int capLimit) {
        int studentCount=1,curSum=0;
        for (int i=0;i<N;i++) {
            if (A[i]>capLimit) return false;
            if (A[i]+curSum > capLimit) {
                studentCount++;
                curSum = A[i];
                
                if (studentCount > M) return false;
            } else {
                curSum+=A[i];
            }
        }
        
        return true;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if (N<M) return -1;
        
        int sum=0,mx=INT_MIN;
        for (int i=0;i<N;i++) {
            sum+=A[i];
            mx = max(mx,A[i]);
        }
        
        if (M == N) return mx;
        
        int low=mx,high=sum,mid,ans;
        while (low<=high) {
            mid = (low+high)/2;
            
            if (isPossible(A,N,M,mid)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends