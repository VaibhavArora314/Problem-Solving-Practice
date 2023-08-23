//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    vector<vector<int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};
    bool bfsHelper(queue<pair<int,int>> &q,vector<vector<int>>& grid) {
        if (q.empty()) return false;
        
        while (!q.empty()) {
            int x=q.front().first,y=q.front().second;
            q.pop();
            
            if (grid[x][y] == 2) return true;
            
            for (int i=0;i<moves.size();i++) {
                int newR=x+moves[i][0],newC=y+moves[i][1];
                
                if (newR>=0 && newR<grid.size() && newC>=0 && newC<grid.size()) {
                    if (grid[newR][newC] == 3) {
                        grid[newR][newC] = 0;
                        q.push({newR,newC});
                    }
                    if (grid[newR][newC] == 2) return true;
                }
            }
        }

        return false;
    }
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) {
        int i,j,sr,sc,n=grid.size();
        for (i=0;i<n;i++) {
            for (j=0;j<n;j++) {
                if (grid[i][j] == 1) {sr=i;sc=j;break;}
            }
        }
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        return bfsHelper(q,grid);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends