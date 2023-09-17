class Solution {
    struct state {
        int mask, node, dist;
    };
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), allVisited = (1<<n)-1;
        queue<state> q;
        set<pair<int,int>> visited;

        for (int i=0;i<n;i++) {
            q.push({1 << i,i,0});
            visited.insert({1<<i,i});
        }

        while (!q.empty()) {
            state cur = q.front();
            q.pop();

            if (cur.mask == allVisited)
                return cur.dist;
            
            for (int neighbor:graph[cur.node]) {
                int newMask = cur.mask | (1<<neighbor);
                
                if (visited.find({newMask,neighbor}) == visited.end()) {
                    q.push({newMask,neighbor,cur.dist+1});
                    visited.insert({newMask,neighbor});
                }
            }
        }

        return -1;
    }
};