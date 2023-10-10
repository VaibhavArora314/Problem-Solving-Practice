class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        vector<int> updatedNums(s.begin(),s.end());
        int ans = nums.size();
        for (int i=0;i<updatedNums.size();i++) {
            int j=upper_bound(updatedNums.begin(),updatedNums.end(),updatedNums[i]+nums.size()-1)-updatedNums.begin();
            if (ans > nums.size()+i-j) ans = nums.size()+i-j;
        }

        return ans;
    }
};