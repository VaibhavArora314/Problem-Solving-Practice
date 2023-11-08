class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i=1;i<n;i++) {
            for (int j=0;j<=i;j++) {
               int temp = INT_MAX;
               if (j != i) temp = min(temp,triangle[i-1][j]);
               if (j != 0) temp = min(temp,triangle[i-1][j-1]);

               triangle[i][j] += temp;
            }
        }

        return *min_element(triangle[n-1].begin(),triangle[n-1].end());
    }
};