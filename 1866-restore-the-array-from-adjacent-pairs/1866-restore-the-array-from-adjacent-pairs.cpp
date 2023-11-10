class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> m;

        for (auto a:adjacentPairs) {
            m[a[0]].push_back(a[1]);
            m[a[1]].push_back(a[0]);
        }

        int start = -1;
        for (auto itr = m.begin();itr != m.end();itr++) {
            if (itr->second.size() == 1) {
                start = itr->first;
                break;
            }
        }

        vector<int> ans;
        
        int cur = start,prev=100001;
        while (true) {
            ans.push_back(cur);

            if (m[cur].size() == 1 && m[cur][0] == prev) break;
            if (m[cur].size() == 1) {
                prev = cur;
                cur = m[cur][0];
                continue;
            }

            int temp;
            if (m[cur][0] == prev) temp = m[cur][1];
            else temp = m[cur][0];

            prev = cur;
            cur = temp;
        }

        return ans;
    }
};