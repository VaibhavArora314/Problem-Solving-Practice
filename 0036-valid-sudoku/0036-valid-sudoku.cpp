class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0;i<9;i++) {
            unordered_set<char> row,col;

            for (int j=0;j<9;j++) {
                if (board[i][j] != '.') {
                    if (row.find(board[i][j]) != row.end()) return false;
                    row.insert(board[i][j]);
                }

                if (board[j][i] != '.') {
                    if (col.find(board[j][i]) != col.end()) return false;
                    col.insert(board[j][i]);
                }
            }
        }

        for (int i=0;i<9;i+=3) {
            for (int j=0;j<9;j+=3) {
                unordered_set<char> box;

                for (int x=0;x<3;x++) {
                    for (int y=0;y<3;y++) {
                        if (board[i+x][j+y] == '.') continue;

                        if (box.find(board[i+x][j+y]) != box.end()) return false;
                        box.insert(board[i+x][j+y]);
                    }
                }
            }
        }

        return true;
    }
};