//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int,int> m,c;
        for (int i=0;i<n;i++) {
            int x=arr[i];
            if (m.find(x) == m.end()) {m[x] = 1;
                if (c.find(m[x]) == c.end()) c[m[x]] = 1;
                else c[m[x]]++;
            }
            else {
                c[m[x]]--;
                m[x]++;
                if (c.find(m[x]) == c.end()) c[m[x]] = 1;
                else c[m[x]]++;
            }

        }
        for(unordered_map<int,int>::iterator itr = c.begin();itr != c.end();itr++) {
            if (itr->second > 1) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends