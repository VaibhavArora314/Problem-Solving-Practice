class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int max = *max_element(nums.begin(),nums.end());
        if (max >= target) return 1;

        int l=0,r=0,seriesSum = nums[0],minSize=INT_MAX;
        for (int i=1;i<nums.size();i++) {
            seriesSum += nums[i];r++;
            if (seriesSum < target) continue;
            
            while (l<=r && seriesSum >= target) {
                minSize = min(minSize,r-l+1);
                seriesSum -= nums[l++];
            }
        }

        return minSize==INT_MAX ? 0 : minSize;
    }
};