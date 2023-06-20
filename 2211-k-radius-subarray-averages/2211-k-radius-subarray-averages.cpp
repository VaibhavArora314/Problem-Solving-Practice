class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(),-1);
        if (nums.size() <= 2*k) return ans;

        vector<long long> sums(nums.size()-2*k,0);
        int i;
        for (i=0;i<=2*k;i++) sums[0] += nums[i];

        int j=1;
        while (i<nums.size()) {
            sums[j] = sums[j-1] + nums[i] - nums[i-2*k-1];
            i++;
            j++;
        }

        for (i=k;i<ans.size()-k;i++) {
            ans[i] = sums[i-k]/(2*k+1);
        }

        return ans;
    }
};