//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
        {
            unordered_set<int> s;
            vector<int> ans, i(3,0);
            while (i[0]<n1 && i[1]<n2 && i[2]<n3) {
                if (A[i[0]] == B[i[1]] && B[i[1]] == C[i[2]]) {
                    if (s.find(A[i[0]]) == s.end()) {
                        ans.push_back(A[i[0]]);
                        s.insert(A[i[0]]);
                    }
                    i[0]++;i[1]++;i[2]++;
                } else {
                    int k=0;
                    if (B[i[1]] < A[i[0]]) k = 1;
                    if (k== 0 && C[i[2]] < A[i[0]]) k = 2;
                    if (k== 1 && C[i[2]] < B[i[1]]) k = 2;
                    
                    i[k]++;
                }
            }
            return ans;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends