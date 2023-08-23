//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<vector<int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};
    void helper(int i,int j,int oldColor,int newColor,vector<vector<int>> &image) {
        int n=image.size(),m=image[0].size();
        
        if (i<0 || j<0 || i>=n || j>=m) return;
        if (image[i][j] != oldColor) return;
        
        image[i][j] = newColor;
        
        for (int k=0;k<moves.size();k++) {
            int x=i+moves[k][0],y=j+moves[k][1];
            
            if (x<0 || y<0 || x>=n || y>=m || image[x][y] != oldColor) continue;
            helper(i+moves[k][0],j+moves[k][1],oldColor,newColor,image);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int startColor = image[sr][sc];
        
        if (startColor == newColor) return image;
        
        helper(sr,sc,startColor,newColor,image);
        
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends