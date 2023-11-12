class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int,vector<int>> m;

        for (int r=0;r<routes.size();r++) {
            for (int stop:routes[r])
                m[stop].push_back(r);
        }

        queue<int> q;
        unordered_set<int> vis;

        for (int route:m[source]) {
            q.push(route);
            vis.insert(route);
        }

        int busCount = 1;
        while (!q.empty()) {
            int size = q.size();

            for (int i=0;i<size;i++) {
                int route = q.front();
                q.pop();

                for (auto stop:routes[route]) {
                    if (stop == target) return busCount;

                    for (auto nextRoute:m[stop]) {
                        if (vis.find(nextRoute) == vis.end()) {
                            vis.insert(nextRoute);
                            q.push(nextRoute);
                        }
                    }
                }

            }
            busCount++;
        }

        return -1;
    }
};