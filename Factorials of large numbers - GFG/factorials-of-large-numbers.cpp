//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        vector<int> ans(1,1);
        int carry = 0;
        
        for (int i=2;i<=N;i++) {
            for (int j=0;j<ans.size();j++) {
                ans[j] = ans[j]*i+carry;
                carry = ans[j]>=10 ? ans[j]/10 : 0;
                ans[j] = ans[j]%10;
            }
            while (carry) {
                ans.push_back(carry%10);
                carry/=10;
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends