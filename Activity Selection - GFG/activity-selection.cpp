//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> m;
        // unordered_map<int,int>::iterator itr;
        for (int i=0;i<n;i++) {
            // itr = m.find(start);
            // if (itr == m.end() || itr.second < end)
            m.push_back({end[i],start[i]});
        }
        sort(m.begin(),m.end());
        int ans=0,curTime=-1;
        for (int i=0;i<n;i++) {
            if (m[i].second <= curTime) continue;
            ans++;
            curTime = m[i].first;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends