//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    vector<vector<int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
    void bfs(int N, int M, vector<vector<int>> &A,queue<pair<int,int>> q,int curDist,vector<vector<int>> &dist ) {
        queue<pair<int,int>> nextQ;
        
        if (q.empty()) return;
        
        pair<int,int> temp;
        while (!q.empty()) {
            temp = q.front();
            q.pop();
            
            for (int i=0;i<4;i++) {
                if (temp.first+moves[i][0] < N && temp.first+moves[i][0] >=0 && 
                    temp.second+moves[i][1] < M && temp.second+moves[i][1] >= 0 &&
                    A[temp.first+moves[i][0]][temp.second+moves[i][1]] == 1) {
                    nextQ.push({temp.first+moves[i][0],temp.second+moves[i][1]});
                    A[temp.first+moves[i][0]][temp.second+moves[i][1]] = 0;
                    dist[temp.first+moves[i][0]][temp.second+moves[i][1]] = curDist;
                }
            }
        }
        
        bfs(N,M,A,nextQ,curDist+1,dist);
    }
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if (X == 0 && Y == 0) return 0;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> dist(N,vector<int>(M,-1));
        bfs(N,M,A,q,1,dist);
        return dist[X][Y];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends