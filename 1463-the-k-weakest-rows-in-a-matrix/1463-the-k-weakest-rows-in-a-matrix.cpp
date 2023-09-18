class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> rowStrength;
        for (int i=0;i<mat.size();i++)
            rowStrength.push_back({accumulate(mat[i].begin(),mat[i].end(),0),i});
        
        sort(rowStrength.begin(),rowStrength.end());

        vector<int> result;
        for (int i=0;i<k;i++)
            result.push_back(rowStrength[i].second);
        return result;
    }
};