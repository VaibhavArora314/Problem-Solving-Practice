//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
        long long evenCount=0,oddCount=0;
        for (int i=s.size()-1;i>=0;i-=2) {
            if (s[i] == '1') oddCount++;
            
            if (i-1>=0 && s[i-1] == '1') evenCount++;
        }
        
        return (oddCount-evenCount)%3 == 0 ? 1 : 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends