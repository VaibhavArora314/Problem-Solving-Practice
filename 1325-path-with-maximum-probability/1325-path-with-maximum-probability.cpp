class Solution {
    void helper(int n,int start, int end, vector<double> &prob, unordered_map<int,vector<pair<int,double>>>& adjacentList) {
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        int cur,node; double curProb,edgeProb;
        pair<double,int> temp;

        while (!pq.empty()) {
            temp = pq.top();
            curProb = temp.first;
            cur = temp.second;
            
            if (cur == end) return;
            
            pq.pop();


            if (adjacentList.find(cur) == adjacentList.end()) {
                continue;
            };

            for (int i=0;i<adjacentList[cur].size();i++) {
                node = adjacentList[cur][i].first;
                edgeProb = adjacentList[cur][i].second;

                if (prob[node] < curProb*edgeProb) {
                    prob[node] = curProb*edgeProb;
                    pq.push({prob[node],node});
                }
            }
            
        }
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,vector<pair<int,double>>> adjacentList;

        for (int i=0;i<edges.size();i++) {
            int a = edges[i][0], b = edges[i][1];

            if (adjacentList.find(a) == adjacentList.end()) adjacentList[a] = {{b,succProb[i]}};
            else adjacentList[a].push_back({b,succProb[i]});

            if (adjacentList.find(b) == adjacentList.end()) adjacentList[b] = {{a,succProb[i]}};
            else adjacentList[b].push_back({a,succProb[i]});
        }

        // for (int i=0;i<adjacentList[start].size();i++) {
        //     cout<<adjacentList[start][i].first<<" "<<adjacentList[start][i].second<<endl;
        // }

        vector<double> prob(n,0);
        prob[start] = 1.0;

        helper(n,start,end,prob,adjacentList);

        return prob[end];
    }
};