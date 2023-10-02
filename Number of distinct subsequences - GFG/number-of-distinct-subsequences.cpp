//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
    long long MOD = 1000000007;
  public:	
	int distinctSubsequences(string s) {
	    vector<long long> dp(s.length()+1);
	    unordered_map<char,long long> hash;
	    
	    dp[0] = 1;
	    
	    for (int i=1;i<=s.length();i++) {
	        dp[i] = (2*dp[i-1])%MOD;
	        
	        if (hash.find(s[i-1]) != hash.end()) {
	            dp[i] = (dp[i] - hash[s[i-1]])%MOD;
	            if (dp[i] < 0) dp[i] += MOD;
	        }
	        
	        hash[s[i-1]] = dp[i-1];
	    }
	    
	    return dp[s.length()]%MOD;
	}
};


//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends