//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    void helper(int curRow,int curCol,vector<vector<int>> &m,string curPath,vector<string>& paths) {
        if (curRow < 0 || curCol < 0 || curRow >= m.size() || curCol >= m.size()) return;
        if (m[curRow][curCol] == 0) return;
        if (curRow == m.size()-1 && curCol == m.size()-1) {
            paths.push_back(curPath);
            return;
        }
        
        m[curRow][curCol] = 0;
        
        helper(curRow+1,curCol,m,curPath+'D',paths);
        helper(curRow,curCol-1,m,curPath+'L',paths);
        helper(curRow,curCol+1,m,curPath+'R',paths);
        helper(curRow-1,curCol,m,curPath+'U',paths);
        
        m[curRow][curCol] = 1;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if (m[0][0] == 0) return {};
        
        vector<string> paths;
        helper(0,0,m,"",paths);
        return paths;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends