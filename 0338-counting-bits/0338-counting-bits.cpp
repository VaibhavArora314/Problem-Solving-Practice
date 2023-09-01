class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) return {0};
        if (n == 1) return {0,1};

        vector<int> ans(n+1,0);
        ans[0] = 0;
        ans[1] = 1;

        for (int i=2;i<=n;i*=2) {
            for (int j=i,k=0;k<i && j<=n;k++,j++)
                ans[j] = ans[k]+1;
        }
        
        return ans;
    }
};