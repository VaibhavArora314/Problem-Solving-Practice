class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2,j=nums.size()-1;

        while (i>=0 && nums[i]>=nums[i+1]) {
            i--;
        }

        if (i<0) {
            sort(nums.begin(),nums.end());
            return;
        }

        while (nums[j] <= nums[i]) j--;
        swap(nums[j],nums[i]);

        i=i+1,j=nums.size()-1;
        while (i<j) {
            swap(nums[i++],nums[j--]);
        }
    }
};