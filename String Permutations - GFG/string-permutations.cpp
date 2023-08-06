//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    void helper(string curS,string S,vector<int> included,vector<string>& ans) {
        if (curS.length() == S.length()) {ans.push_back(curS);return;}
        
        for (int i=0;i<S.length();i++) {
            if (included[i] == 0) {
                included[i] = 1;
                helper(curS+S[i],S,included,ans);
                included[i] = 0;
            }
        }
    }
    public:
    vector<string> permutation(string S) {
        vector<string> ans;
        vector<int> included(S.length(),0);
        helper("",S,included,ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends