//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int getSetBits(int n) {
        int c=0;
        while (n) {
            if (n&1) c++;
            n = n>>1;
        }
        return c;
    }
public:
	int is_bleak(int n) {
        for (int i = n-ceil(log2(n));i<n;i++) {
            if (i + getSetBits(i) == n) return 0;
        }
        return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends