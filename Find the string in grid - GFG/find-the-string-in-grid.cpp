//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool helper(int i,int j,vector<vector<char>>& grid,string word) {
        int k=0,n=grid.size(),m=grid[0].size();
        
        // right
        for (k=1;k<word.size() && j+k<m;k++) {
            if (grid[i][j+k] != word[k]) break;
        }
        if (k == word.size()) return true;

        //left
        for (k=1;k<word.size() && j-k>=0;k++) {
            if (grid[i][j-k] != word[k]) break;
        }
        if (k == word.size()) return true;        
        
        // down
        for (k=1;k<word.size() && i+k<n;k++) {
            if (grid[i+k][j] != word[k]) break;
        }
        if (k == word.size()) return true; 
        
        // up
        for (k=1;k<word.size() && i-k>=0;k++) {
            if (grid[i-k][j] != word[k] ) break;
        }
        if (k == word.size()) return true; 
        
        //down right
        for (k=1;k<word.size() && i+k<n && j+k<m;k++) {
            if (grid[i+k][j+k] != word[k]) break;
        }
        if (k == word.size()) return true;

        
        //down left
        for (k=1;k<word.size() && i+k<n && j-k>=0;k++) {
            if (grid[i+k][j-k] != word[k]) break;
        }
        if (k == word.size()) return true;
        
        // up right
        for (k=1;k<word.size() && i-k>=0 && j+k<m;k++) {
            if (grid[i-k][j+k] != word[k]) break;
        }
        if (k == word.size()) return true;
        
        // up left
        for (k=1;k<word.size() && i-k>=0 && j-k>=0;k++) {
            if (grid[i-k][j-k] != word[k]) break;
        }
        if (k == word.size()) return true;            
        
        return false;
    }
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>> ans;
	    
	    for (int i=0;i<grid.size();i++) {
	        for (int j=0;j<grid[0].size();j++) {
	            if (grid[i][j] == word[0] && helper(i,j,grid,word))
	                ans.push_back({i,j});
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends