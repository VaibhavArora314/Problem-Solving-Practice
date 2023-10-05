//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int helper(string s, int k) {
        int n = s.size();
        
        long long int ans = 0;
        int left = 0, count = 0;
        vector<int>hash(26, 0);
        
        for(int right=0; right<n; right++) {
            int index = s[right]-'a';
            if(hash[index] == 0) count++;
            hash[index]++;
            
            while(left <= right && count > k){
                hash[s[left]-'a']--;
                if(!hash[s[left]-'a']) count--;
                left++;
            }
            if(left <= right) ans += (right-left+1);
        }
        return ans;
    }
  
    long long int substrCount (string s, int k) {
        return helper(s, k) - helper(s,k-1);
 }
};


//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends