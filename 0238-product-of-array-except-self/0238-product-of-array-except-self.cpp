class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct=1,countZero=0,lastZero=-1;

        for (int i=0;i<nums.size();i++) {
            if (nums[i] == 0) {
                countZero++;
                lastZero = i;

                if (countZero == 2) return vector<int>(nums.size(),0);

                continue;
            }

            totalProduct *= nums[i];
        }

        if (countZero == 1) {
            vector<int> ans(nums.size(),0);
            ans[lastZero] = totalProduct;
            return ans;
        }

        vector<int> ans(nums.size(),totalProduct);
        for (int i=0;i<nums.size();i++) ans[i] /= nums[i];
        return ans;
    }
};