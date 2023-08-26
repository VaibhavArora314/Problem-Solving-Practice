//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i=0,j=0,uniqueCount=0,ans=-1;
        unordered_map<char,int> m;

        while (j<s.size()) {
            m[s[j]]++;
            if (m[s[j]] == 1) uniqueCount++;
            
            if (uniqueCount == k) ans = max(ans,j-i+1);
            else if (uniqueCount > k) {
                while (i<j) {
                    m[s[i]]--;
                    i++;
                    if (m[s[i-1]] == 0) {uniqueCount--;break;}
                }
            }
            
            // cout<<i<<" "<<j<<" "<<uniqueCount<<" "<<ans<<endl;
            
            j++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends