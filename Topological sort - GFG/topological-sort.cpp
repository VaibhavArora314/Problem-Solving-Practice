//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void dfs(int V,int cur,vector<int> adj[],vector<int> &visited,vector<int> &top) {
        for (int i=0;i<adj[cur].size();i++) {
            if (visited[adj[cur][i]] == 0) {
                visited[adj[cur][i]] = 1;
                dfs(V,adj[cur][i],adj,visited,top);
            }
        }
        
        top.push_back(cur);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        vector<int> visited(V,0),top;
        for (int i=0;i<V;i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                dfs(V,i,adj,visited,top);
            }
        }
        
        reverse(top.begin(),top.end());
        
        // for (int i=0;i<top.size();i++) cout<<top[i]<<" ";
        // cout<<endl;
        
        return top;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends