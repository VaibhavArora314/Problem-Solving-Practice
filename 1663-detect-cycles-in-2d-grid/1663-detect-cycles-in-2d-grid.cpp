class Solution {
    vector<vector<int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};
    bool dfsHelper(int i,int j,int m,int n,char target,pair<int,int> prev,vector<vector<char>> &grid,vector<vector<int>> &visited) {
        if (i<0 || j<0 || i>=m || j>=n) return false;
        visited[i][j] = 1;

        for (int k=0;k<4;k++) {
            int ni = i+moves[k][0],nj=j+moves[k][1];

            if (ni<0 || nj<0 || ni>=m || nj>=n) continue;
            if (grid[ni][nj] != target) continue;
            if (ni == prev.first && nj == prev.second) continue;
            
            if (visited[ni][nj] == 1) return true;
            if (dfsHelper(ni,nj,m,n,target,{i,j},grid,visited)) return true;
        }

        return false;
    } 
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                cout<<i<<" "<<j<<endl;
                if (visited[i][j] == 0 && dfsHelper(i,j,m,n,grid[i][j],{-1,-1},grid,visited)) 
                    return true;
            }
        }

        return false;
    }
};