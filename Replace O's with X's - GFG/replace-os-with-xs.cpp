//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    vector<vector<int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfsHelper(int i,int j,int m,int n,vector<vector<char>>& dc,vector<vector<char>> mat) {
        dc[i][j] = 'O';
        
        stack<pair<int,int>> stk;
        stk.push({i,j});
        
        // cout<<i<<" "<<j<<endl;
        
        while (!stk.empty()) {
            auto a = stk.top();
            int ni = a.first,nj = a.second;
            stk.pop();
            
            for (int k=0;k<4;k++) {
                int x = moves[k][0]+ni,y=moves[k][1]+nj;
                
                if (x<0 || x>=n || y<0 || y>=m || mat[x][y] != 'O' || dc[x][y] == 'O') continue;
                
                dc[x][y] = 'O';
                stk.push({x,y});
            }
        }
        

    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> dc(n,vector<char>(m,'X'));
        
        for (int i=0;i<n;i++) {
            if (mat[i][0] == 'O' && dc[i][0] == 'X') {
                dfsHelper(i,0,m,n,dc,mat);
            }
            
            if (mat[i][m-1] == 'O' && dc[i][m-1] == 'X') {
                dfsHelper(i,m-1,m,n,dc,mat);
            }
        }
        
        for (int i=0;i<m;i++) {
            if (mat[0][i] == 'O' && dc[0][i] == 'X') {
                dfsHelper(0,i,m,n,dc,mat);
            }
            
            if (mat[n-1][i] == 'O' && dc[n-1][i] == 'X') {
                dfsHelper(n-1,i,m,n,dc,mat);
            }
        }
        
        return dc;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends