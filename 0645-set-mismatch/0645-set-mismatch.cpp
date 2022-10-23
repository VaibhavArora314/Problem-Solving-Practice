class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int missing=0,duplicate=-1;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] == missing+1) missing++;
            if (i > 0 && nums[i] == nums[i-1]) duplicate=nums[i];
        }
        
        return {duplicate,missing+1};
    }
};