class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pas(numRows);

        pas[0].push_back(1);
        if (numRows == 1) return pas;
        pas[1].push_back(1);
        pas[1].push_back(1);
        if (numRows == 2) return pas;

        for (int i=2;i<numRows;i++) {
            pas[i].push_back(1);

            for (int j=0;j<pas[i-1].size()-1;j++) {
                pas[i].push_back(pas[i-1][j]+pas[i-1][j+1]);
            }

            pas[i].push_back(1);
        }

        return pas;
    }
};