class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l=k-1,r=k+1,mn=nums[k],ans=nums[k];

        while (true) {
            if (l >= 0 && r < nums.size()) {
                if (nums[l] >= nums[r]) {
                    mn = min(mn,nums[l]);
                    ans = max(ans,mn*(r-l));
                    l--;
                } else {
                    mn = min(mn,nums[r]);
                    ans = max(ans,mn*(r-l));
                    r++;
                }
            } else if (l >= 0) {
                mn = min(mn,nums[l]);
                ans = max(ans,mn*(r-l));
                l--;
            } else if (r < nums.size()) {
                mn = min(mn,nums[r]);
                ans = max(ans,mn*(r-l));
                r++;
            } else break;
        }

        return ans;
    }
};