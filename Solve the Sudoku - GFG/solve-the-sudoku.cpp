//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    bool findUnassigned(int grid[N][N],int &row,int &col) {
        for  (int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if (grid[i][j] == 0) {
                    row = i; col =j;
                    return true;
                }
            }
        }
        return false;
    }
    bool isSafe(int grid[N][N],int i,int j,int num) {
        for (int k=0;k<9;k++) {
            if (grid[i][k] == num || grid[k][j] == num) return false;
        }
        
        int a=(i/3)*3,b=(j/3)*3;
        
        for (int x=0;x<=2;x++) {
            for (int y=0;y<=2;y++) {
                if (grid[a+x][b+y] == num) return false;
            }
        }
        return true;

    }
    bool solve(int grid[N][N]) {
        int row,col;
        if (!findUnassigned(grid,row,col)) return true;
        
        for (int i=1;i<=9;i++) {
            if (isSafe(grid,row,col,i)) {
                grid[row][col] = i;
                
                if (solve(grid))
                    return true;
                
                grid[row][col] = 0;
            }
        }
        return false;
    }
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  { 
        return solve(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        solve(grid);
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends