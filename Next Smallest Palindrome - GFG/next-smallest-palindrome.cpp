//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
	    int inc=1,i=0,j=n-1;
	    
	    bool allNine = true;
	    for (int i=0;i<n;i++) {
	        if (num[i] != 9) allNine = false;
	    }
	    
	    if (allNine) {
	        vector<int> a(n+1,0);
	        a[n] = a[0] = 1;
	        return a;
	    }
	    
	    while (i<j) {
	        if (num[i] != num[j]) {
	            if (num[j] < num[i]) inc=0;
	            else inc=1;
	            
	            num[j] = num[i];
	        }
	        i++;
	        j--;
	    }
	    
	    if (inc) {
	        if (i==j) {
	            num[i]++;
	            if (num[i] >= 10) {
	                num[i] = 0;
	                j=i+1;
	                i--;
	                int prev=1;
	                while (i>=0 && prev) {
	                    num[i]++;
	                    prev = num[i]/10;
	                    num[i] %= 10;
	                    num[j++] = num[i--];
	                }
	            }
	        }
	        else {num[i]++;num[j]++;
	            if (num[i] >= 10) {
	                num[i] = num[j] = 0;
	                swap(i,j);
	                i--;j++;
	                
	                int prev=1;
	                while (i>=0 && prev) {
	                    num[i]++;
	                    prev = num[i]/10;
	                    num[i] %= 10;
	                    num[j++] = num[i--];
	                }
	            }
	        }
	    }
	    
	    return vector<int>(num,num+n);
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends