//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string S) { 
        vector<vector<int>> lps(S.length(),vector<int>(S.length(),-1));
        
        for (int i=0;i<S.length();i++) lps[i][i] = 1;
        
        for (int d = 2;d<=S.length();d++) {
            for (int i=0;i+d-1<S.length();i++) {
                int j = i + d - 1;
                
                if (S[i] == S[j]) {
                    if (d == 2) lps[i][j] = 2;
                    else lps[i][j] = 2 + lps[i+1][j-1];
                } else 
                    lps[i][j] = max(lps[i+1][j],lps[i][j-1]);
            }
        }
        
        return S.length() - lps[0][S.length()-1];
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends