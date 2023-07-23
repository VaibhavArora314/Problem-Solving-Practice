//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        vector<int> tr(n,0),tl(n,0);
        
        for (int i=0;i<n;i++) {
            tl[i] = max(i > 0 ? tl[i-1] : 0,arr[i]);
        }
        
        for (int j=n-1;j>=0;j--) {
            tr[j] = max(arr[j],j < n-1 ? tr[j+1] : 0);
        }
        
        long long ans=0;
        for (int i=0;i<n;i++) {
            ans += min(tr[i],tl[i])-arr[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends