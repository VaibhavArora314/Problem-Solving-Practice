//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool helperDfs(int i,int prev,vector<int> adj[],vector<int> &visited) {
        if (visited[i] == 1) return true;
        
        visited[i] = 1;
        
        for (int j:adj[i]) {
            if (prev == j) continue;
            
            if (helperDfs(j,i,adj,visited)) return true;
        }
        
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        
        for (int i=0;i<V;i++) {
            if (visited[i] == 0 && helperDfs(i,-1,adj,visited)) return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends