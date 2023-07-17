//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    queue<char> q;
		    unordered_map<char,int> m;
		    
		    string ans = A;
		    q.push(A[0]);
		    m[A[0]] = 1;
		    for (int i=1;i<A.size();i++) {
		        if (m.find(A[i]) == m.end()) m[A[i]] = 1;
		        else m[A[i]]++;
		        q.push(A[i]);
		        
		        while (!q.empty()) {
		            if (m[q.front()] > 1) q.pop();
		            else {
		                ans[i] = q.front();
		                break;
		            }
		        }
		        if (q.empty()) ans[i] = '#';
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends