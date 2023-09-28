class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=nums.size()-1;

        while (i<j) {
            if (nums[i]%2 == 1 && nums[j]%2 == 0) swap(nums[i++],nums[j--]);
            else {
                while (i<j && nums[i]%2 == 0) i++;
                while (i<j && nums[j]%2 == 1) j--;
            }
        }

        return nums;
    }
};