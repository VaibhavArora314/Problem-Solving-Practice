//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        int count=0,temp=0;
        map<int,vector<int>> m;
        for (int i=0;i<n;i++) {
            count=0;temp=arr[i];
            while (temp) {
                if (temp&1) count++;
                temp=temp>>1;
            }
            m[count].push_back(arr[i]);
        }
        
        int i=0;
        for (auto itr=m.rbegin();itr!=m.rend() && i<n;itr++) {
            int j=0;
            while (j<itr->second.size()) {
                arr[i++] = itr->second[j++];
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends