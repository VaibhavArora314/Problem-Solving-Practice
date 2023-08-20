//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    void helper(int i,int mx,unordered_set<string>& dict,string s,vector<string> &ans,string cur) {
        if (i == s.size()) {
            ans.push_back(cur);
            return;
        }
        
        
        string temp;
        for (int j=0;j<mx && i+j<s.size();j++) {
            temp += s[i+j];
            
            if (dict.find(temp) != dict.end())
                helper(i+j+1,mx,dict,s,ans,cur == "" ? temp : cur +" "+temp);
        }
    }
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        unordered_set<string> d;
        int mx=0;
        for (string x:dict) {
            d.insert(x);
            if (x.length() > mx) mx = x.length();
        }
        vector<string> ans;
        helper(0,mx,d,s,ans,"");
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends