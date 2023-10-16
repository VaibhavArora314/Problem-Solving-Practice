class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return {1,1};

        vector<vector<int>> pasTri(rowIndex+1);
        pasTri[0] = {1};
        pasTri[1] = {1,1};

        for (int i=2;i<=rowIndex;i++) {
            pasTri[i].push_back(1);

            for (int j=0;j<pasTri[i-1].size()-1;j++)
                pasTri[i].push_back(pasTri[i-1][j] + pasTri[i-1][j+1]);

            pasTri[i].push_back(1);
        }

        return pasTri[rowIndex];
    }
};