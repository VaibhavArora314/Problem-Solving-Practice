class Solution {
    int moves[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(int curRow,int curCol,int row,int col,vector<vector<int>> &grid,vector<vector<int>> &visited) {
        if (curRow < 0 || curCol<0 || curRow >= row || curCol>=col || grid[curRow][curCol] == 1 || visited[curRow][curCol] == 1) return false;
        
        // cout<<curRow<<" "<<curCol<<endl;

        if (curRow == row-1) return true;

        visited[curRow][curCol] = 1;
        bool ans = false;
        for (int i=0;i<4;i++) {
            ans = ans || dfs(curRow+moves[i][0],curCol+moves[i][1],row,col,grid,visited);
            if (ans) return true;
        }

        return ans;
    }
    bool topToBottomPossible(int row,int col,vector<vector<int>> &grid) {
        vector<vector<int>> visited(row,vector<int>(col,0));
        for (int i=0;i<col;i++) {
            if (grid[0][i] == 0 && visited[0][i] == 0) {
                if (dfs(0,i,row,col,grid,visited)) return true;
            }
        }

        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l=0,r=cells.size();

        while (l<=r) {
            int mid = (l+r)/2;
            // cout<<mid<<endl;
            vector<vector<int>> grid(row,vector<int>(col,0));  
            for (int i=0;i<mid;i++) {grid[cells[i][0]-1][cells[i][1]-1] = 1;}

            if (topToBottomPossible(row,col,grid)) l = mid+1;
            else r=mid-1;
        }

        return r;
    }
};