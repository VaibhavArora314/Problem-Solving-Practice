//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int getFirstOccurence(int arr[],int n,int x) {
    int l=0,r=n-1,mid;
    
    while (l<r) {
        mid = (l+r)/2;
        if (arr[mid] >= x) r = mid;
        else l = mid+1;
    }
    
    return r;
}

vector<int> find(int arr[], int n , int x) {
    int f = getFirstOccurence(arr,n,x);
    if (arr[f] != x) return {-1,-1};
    if (arr[n-1] == x) return {f,n-1};
    
    int l = getFirstOccurence(arr,n,x+1)-1;
    
    return {f,l};
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends