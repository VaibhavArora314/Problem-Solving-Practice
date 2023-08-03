//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    void dfs(int i,int N,vector<vector<int>> &adjMat,vector<int> &visited,vector<int> &ts) {
        visited[i] = 1;
        
        for (int j=0;j<N;j++) {
            if (adjMat[i][j] > -1 && visited[j] == 0)
                dfs(j,N,adjMat,visited,ts);
        }
        
        ts.push_back(i);
    }
    vector<int> topSort(int N,vector<vector<int>> &adjMat) {
        vector<int> visited(N,0),ts;
        
        for (int i=0;i<N;i++) {
            if (visited[i] == 0)
                dfs(i,N,adjMat,visited,ts);
        }
        
        reverse(ts.begin(),ts.end());
        
        return ts;
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<int>> adjMat(N,vector<int>(N,-1));
        for (int i=0;i<edges.size();i++)
            adjMat[edges[i][0]][edges[i][1]] = edges[i][2];
        
        vector<int> ans(N,-1),ts = topSort(N,adjMat);
        ans[0] = 0;
        
        for (int i=0;i<N;i++) {
            if (ans[ts[i]] == -1) continue;
            
            for (int j=0;j<N;j++) {
                if (adjMat[ts[i]][j] >= 0) {
                    if (ans[j] == -1) ans[j] = ans[ts[i]] + adjMat[ts[i]][j];
                    else ans[j] = min(ans[j],ans[ts[i]] + adjMat[ts[i]][j]);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends