//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> v(100000,-1);
        v[start] = 0;
        
        queue<pair<int,int>> q;
        q.push({start,0});
        
        while (!q.empty()) {
            pair<int,int> x = q.front();
            q.pop();
            
            if (x.first == end) return x.second;
            
            for (auto i:arr) {
                int p = (x.first*i)%100000;
                if (v[p] == -1 || v[p] > x.second+1) {
                    v[p] = x.second+1;
                    q.push({p,x.second+1});
                }
            }
        }
        
        return v[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends