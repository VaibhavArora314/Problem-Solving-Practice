class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size(),n=grid[0].size();
        unordered_set<char> keySet, lockSet;
        int allKeys=0,startRow,startCol;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    keySet.insert(grid[i][j]);
                    allKeys += (1<<(grid[i][j]-'a'));
                }
                if (grid[i][j] >= 'A' && grid[i][j] <= 'F') lockSet.insert(grid[i][j]);
                if (grid[i][j] == '@') {
                    startRow = i;
                    startCol = j;
                }
            }
        }

        queue<vector<int>> q;
        int moves[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        unordered_map<int, vector<vector<bool>>> seen;

        q.push({startRow,startCol,0,0}); // r,c,keys,distance
        seen.emplace(0, vector<vector<bool>>(m,vector<bool>(n,false)));
        seen[0][startRow][startCol] = true;

        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();

            int curRow = cur[0],curCol = cur[1],keys = cur[2], dist = cur[3];

            for (int i=0;i<4;i++) {
                int nextRow = curRow + moves[i][0], nextCol = curCol + moves[i][1];

                if (nextRow < 0 || nextCol < 0 || nextRow >= m || nextCol >= n) continue;

                char cellVal = grid[nextRow][nextCol];
                if (cellVal == '#') continue;

                if (lockSet.find(cellVal) != lockSet.end() && ((1 << (cellVal - 'A')) & keys) == 0) {
                    continue;
                }

                int newKeys = keys;

                if (keySet.find(cellVal) != keySet.end()) {
                    newKeys |= (1 << (cellVal - 'a'));
                    if (seen.find(newKeys) == seen.end()) seen.emplace(newKeys, vector<vector<bool>>(m,vector<bool>(n,false)));
                }


                if (newKeys == allKeys) return dist+1;

                if (seen[newKeys][nextRow][nextCol]) {
                    continue;
                }

                // cout<<nextRow<<" "<<nextCol<<" "<<newKeys<<" "<<dist+1<<endl;

                seen[newKeys][nextRow][nextCol] = true;
                q.push({nextRow, nextCol, newKeys, dist + 1});
            }
        }

        return -1;
    }
};