class Solution {
    vector<vector<int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> dist(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        dist[0][0] = 0;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});

        while (!q.empty()) {
            int d = q.top().first, i = q.top().second.first,j=q.top().second.second;
            q.pop();

            if (d > dist[i][j]) continue;

            for (int k=0;k<4;k++) {
                int ni = i+moves[k][0],nj=j+moves[k][1];

                if (ni < 0 || nj < 0 || ni >= heights.size() || nj >= heights[0].size()) continue;

                if (max(d,abs(heights[ni][nj] - heights[i][j])) < dist[ni][nj]) {
                    dist[ni][nj] = max(d,abs(heights[ni][nj] - heights[i][j]));
                    q.push({dist[ni][nj],{ni,nj}});
                }
            }
        }

        for (auto x:dist) {
            for (auto y:x) cout<<y<<" ";
            cout<<endl;
        }

        return dist[heights.size()-1][heights[0].size()-1];
    }
};