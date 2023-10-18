//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool dfs(int i, vector<int> adj[], vector<int>& visited, vector<int>& inPath, vector<int>& safe) {
        if (visited[i] == 1) {
            if (inPath[i] == 1) return true; //cycle
            
            return safe[i] != 1;
        }
        
        visited[i] = 1;
        inPath[i] = 1;
        
        for (int j=0;j<adj[i].size();j++) {
            if (dfs(adj[i][j],adj,visited,inPath,safe)) {
                inPath[i] = 0;
                return true;
            }
        }
        
        inPath[i] = 0;
        safe[i] = 1;
        
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> visited(V,0), inPath(V,0),safe(V,0);
        
        for (int i=0;i<V;i++) {
            if (visited[i] == 0) dfs(i,adj,visited,inPath,safe); 
        }
        
        vector<int> ans;
        for (int i=0;i<V;i++) {
            if (safe[i]) ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends