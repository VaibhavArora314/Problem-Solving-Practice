class Solution {
    int helper(int i,vector<int> &distributions, vector<int>& cookies,int k,int zeroCount) {
        // if (cookies.size() - i < zeroCount) return INT_MAX;

        if (cookies.size() == i) return *max_element(distributions.begin(),distributions.end());

        int ans = INT_MAX;
        for (int j=0;j<k;j++) {
            if (distributions[j] == 0) zeroCount--;
            distributions[j] += cookies[i];

            ans = min(helper(i+1,distributions,cookies,k,zeroCount),ans);

            distributions[j] -= cookies[i];
            if (distributions[j] == 0) zeroCount++;
        }

        return ans;
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distributions(k);

        return helper(0,distributions,cookies,k,k);
    }
};