//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define MOD 1000000007

class Solution{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n) {
        long long f1=1,f2=2,f3=4,fans=0;
        if (n == 1) return f1;
        if (n == 2) return f2;
        if (n == 3) return f3;
        
        for (int i=4;i<=n;i++) {
            fans = (f1 + f2 + f3)%MOD;
            f1 = f2;
            f2 = f3;
            f3 = fans;
        }
        
        return fans;
    }
};




//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends