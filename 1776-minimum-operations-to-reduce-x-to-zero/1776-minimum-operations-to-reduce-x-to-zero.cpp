class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = 0,target,minElement=INT_MAX;
        for (auto n:nums) {
            totalSum+=n;
            minElement=min(minElement,n);
        }
        if (totalSum < x || minElement > x) return -1;
        target = totalSum -= x;

        int maxLen=0,curSum=0,left=0,right=0;
        for (right=0;right<n;right++) {
            curSum += nums[right];

            while (left <= right && curSum > target)
                curSum -= nums[left++];
            
            if (curSum == target) maxLen = max(maxLen,right-left+1);
        }

        return n-maxLen;
    }
};