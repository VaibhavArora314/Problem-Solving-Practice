//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    int moves[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
public:
    int Count(vector<vector<int> >& matrix) {
        int n=matrix.size(),m=matrix[0].size(),ans=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (matrix[i][j] == 0) continue;
                
                int countZ = 0;
                
                for (int k=0;k<8;k++) {
                    int x = i+moves[k][0],y=j+moves[k][1];
                    
                    if (x >= 0 && y>=0 && x<n && y<m && matrix[x][y] == 0) countZ++;
                }
                
                // cout<<i<<" "<<j<<" "<<countZ<<endl;
                
                if (countZ>0 && (countZ&1) == 0) ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends