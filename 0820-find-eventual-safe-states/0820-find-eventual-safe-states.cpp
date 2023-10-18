class Solution {
    bool dfs(int i,vector<vector<int>>& graph,vector<int>& visited,vector<int>& inPath,vector<int>& safeStates) {
        if (visited[i]) {
            if (inPath[i]) return true; // cycle detected

            return safeStates[i] != 1;
        }
        
        visited[i] = 1;
        inPath[i] = 1;
        for (int j:graph[i]) {
            if (dfs(j,graph,visited,inPath,safeStates)) {
                inPath[i] = 0;
                return true;
            }
        }
        inPath[i] = 0;
        safeStates[i] = 1;

        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0), inPath(n,0), safeStates(n,0);

        for (int i=0;i<n;i++) {
            if (visited[i] == 0) 
                dfs(i,graph,visited,inPath,safeStates);
        }

        vector<int> ans;
        for (int i=0;i<n;i++) {
            if (safeStates[i])
                ans.push_back(i);
        }
        return ans;
    }
};