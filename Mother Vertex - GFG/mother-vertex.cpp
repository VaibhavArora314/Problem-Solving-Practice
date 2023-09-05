//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    void dfsHelper(int i,vector<int> &visited,vector<int>adj[]) {
        visited[i] = 1;
        
        for (int x:adj[i]) {
            if (visited[x] == 0)
                dfsHelper(x,visited,adj);
        }
    }
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int> visited(V,0);
	    int mother_vertex = -1;
	    
	    for (int i=0;i<V;i++) {
	        if (visited[i] == 0) {
	            dfsHelper(i,visited,adj);
	            
	            mother_vertex = i;
	        }
	    }
	    
	    fill(visited.begin(),visited.end(),0);
	    dfsHelper(mother_vertex,visited,adj);
	    if (*min_element(visited.begin(),visited.end()) == 0) mother_vertex = -1;
	    
	    return mother_vertex;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends