//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};

class Solution
{
    public:
    int countFractions(int n, int num[], int den[])
    {
        unordered_map<pair<int,int>,int,pair_hash> m;
        int ans=0;
        for (int i=0;i<n;i++) {
            int gcd = __gcd(num[i],den[i]);
            num[i] /= gcd;
            den[i] /= gcd;
            if (m.find({den[i]-num[i],den[i]}) != m.end()) ans+=m[{den[i]-num[i],den[i]}];
            m[{num[i],den[i]}]++;
        }
        return ans;
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends