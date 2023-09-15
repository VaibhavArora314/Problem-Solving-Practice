struct ComparePair {
    bool operator()(const pair<int, vector<int>>& p1, const pair<int, vector<int>>& p2) {
        return p1.first > p2.first;
    }
};

class Solution {
    int setFind(int i,vector<int> parent) {
        while (parent[i] >= 0) {
            i = parent[i];
        }

        return i;
    }
    void setUnion(int i,int j,vector<int> &parent,vector<int> &rank) {
        int pi = setFind(i,parent),pj=setFind(j,parent);

        if  (pi != pj) {
            if (rank[pi] >= rank[pj]) {
                parent[pj] = pi;
                rank[pi] += rank[pj];
            } else {
                parent[pi] = pj;
                rank[pj] += rank[pi];
            }
        }
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> rank(n,1);
        vector<int> parent(n,-1);

        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, ComparePair> pq;

        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++)
                pq.push({abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]),{i,j}});
        }

        int c = n-1,ans=0;
        while (!pq.empty() && c>0) {
            vector<int> p = pq.top().second;

            if (setFind(p[0],parent) != setFind(p[1],parent)) {
                ans += pq.top().first;
                c--;

                setUnion(p[0],p[1],parent,rank);
            }

            pq.pop();
        }

        return ans;
    }
};