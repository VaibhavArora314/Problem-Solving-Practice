class Solution {
    int helper(int i,vector<int> prev[],vector<int>& minTimes,vector<int>& visited) {
        if (visited[i] != 0 || prev[i].empty()) return minTimes[i];

        int temp=0;
        for (int j:prev[i])
            temp = max(temp,helper(j,prev,minTimes,visited));
        
        minTimes[i] += temp; 
        visited[i] = 1;

        return minTimes[i];
    }
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> prev[n];
        for (auto rel:relations)
            prev[rel[1]-1].push_back(rel[0]-1);

        vector<int> minTimes(time),visited(n,0);
        for (int i=0;i<n;i++) {
            if (visited[i] == 0 && !prev[i].empty())
                helper(i,prev,minTimes,visited);
        }

        return *max_element(minTimes.begin(),minTimes.end());
    }
};