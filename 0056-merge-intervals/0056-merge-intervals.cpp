class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;
        int i=0;
        while (i<intervals.size()) {
            int begin = intervals[i][0],end=intervals[i][1];
            i++;

            while (i<intervals.size() && intervals[i][0] <= end) {
                end = max(end,intervals[i][1]);
                i++;
            }

            ans.push_back({begin,end});
        }

        return ans;
    }
};