class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> groups;
        unordered_map<int,int> m;

        for (int i=0;i<groupSizes.size();i++) {
            int size = groupSizes[i];

            if (m.find(size) == m.end() || groups[m[size]].size() == size) {
                groups.push_back(vector<int>(1,i));
                m[size] = groups.size()-1;
            } else
                groups[m[size]].push_back(i);
        }

        return groups;
    }
};