//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[],long long l,long long mid,long long h,long long &ans) {
        vector<long long> temp;
        
        long long i = l,j=mid+1;
        while (i<=mid && j<=h) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                ans += (mid-i+1);
                temp.push_back(arr[j++]);
            }
        }
        
        for (;i<=mid;i++) temp.push_back(arr[i]);
        for (;j<=h;j++) temp.push_back(arr[j]);
        
        for (int k=0,i=l;i<=h;i++,k++) {
            arr[i] = temp[k];
        }
    }
    void mergeSort(long long arr[],long long l,long long h,long long &ans) {
        if (l>=h) return;
        
        long long mid = (l+h)/2;
        mergeSort(arr,l,mid,ans);
        mergeSort(arr,mid+1,h,ans);
        merge(arr,l,mid,h,ans);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long ans=0;
        mergeSort(arr,0,N-1,ans);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends