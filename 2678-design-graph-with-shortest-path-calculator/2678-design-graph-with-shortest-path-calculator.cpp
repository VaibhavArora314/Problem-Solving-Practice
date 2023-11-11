class Graph {
    vector<vector<int>> adjMat;
    int n;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        adjMat.resize(n,vector<int>(n,0));

        for (auto e:edges)
            adjMat[e[0]][e[1]] = e[2];
    }
    
    void addEdge(vector<int> edge) {
        adjMat[edge[0]][edge[1]] = edge[2];
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);

        pq.push({0,node1});
        dist[node1] = 0;

        while (!pq.empty()) {
            int d = pq.top().first, node = pq.top().second;
            pq.pop();

            if (node == node2) return d;

            for (int i=0;i<n;i++) {
                if (adjMat[node][i] > 0 && dist[i] > d + adjMat[node][i]) {
                    dist[i] = d + adjMat[node][i];
                    pq.push({d+adjMat[node][i],i});
                } 
            }
        }

        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */