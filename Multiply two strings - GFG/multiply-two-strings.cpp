//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        bool neg=false;
        if (s1[0] == '-') {
            s1 = s1.substr(1,s1.size()-1);
            neg = true;
        }
        if (s2[0] == '-') {
            s2 = s2.substr(1,s2.size()-1);
            neg = neg ? false : true;
        }
        
        for (int i=0;i<s1.size();i++) {
            if (s1[i] != '0') {
                s1 = s1.substr(i,s1.size()-i);
                break;
            }
        }
        
        for (int i=0;i<s2.size();i++) {
            if (s1[i] != '0') {
                s2 = s2.substr(i,s2.size()-i);
                break;
            }
        }
        
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        
        vector<int> ans(s1.size()+s2.size(),0);

        for (int i=0;i<s2.size();i++)  {
            int carry = 0;
            
            for (int j=0;j<s1.size();j++) {
                if (i+j == ans.size()) ans.push_back(0);
                
                int x = ans[i+j]+(s1[j]-'0')*(s2[i]-'0')+carry;
                
                carry = x/10;
                x %= 10;
                
                ans[i+j] = x;
            }
            
            if (carry) {
                int k=i+s1.size();
                while (carry) {
                    if (k==ans.size()) {
                        ans.push_back(0);
                    }
                    
                    ans[k] += carry;
                    carry = ans[k]/10;
                    ans[k++] %= 10;
                }
            }
        }
        
        string s = "";
        for (int i=0;i<ans.size();i++) {
            s += (ans[i]+'0');
        }
        
        int j;
        for (j=s.size()-1;j>=0;j--) {
            if (s[j] != '0') {
                s = s.substr(0,j+1);
                break;
            }
        }
        if (j==-1) s = '0';
        
        if (neg) s += "-";
        reverse(s.begin(),s.end());
        return s;
    }
};


//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends