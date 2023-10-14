class Solution {
    int dp(int i,int remain,vector<int>& cost, vector<int>& time,vector<vector<int>>& memo) {
        if (remain <= 0) return 0;
        if (i == cost.size()) return INT_MAX;
        if (memo[i][remain] != -1) return memo[i][remain];

        int paint = dp(i+1,remain-1-time[i],cost,time,memo),
            dontPaint = dp(i+1,remain,cost,time,memo);
        if (paint < INT_MAX) paint += cost[i];

        memo[i][remain] = min(paint,dontPaint);
        return memo[i][remain];
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> memo(cost.size()+1,vector<int>(cost.size()+1,-1));

        return dp(0,cost.size(),cost,time,memo);
    }
};