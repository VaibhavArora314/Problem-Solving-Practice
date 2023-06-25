class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int countOne = 0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] == 1) countOne++;
        }
        
        if (countOne == 1) return 1;
        if (countOne < 1) return 0;
        
        long long ans = 1;
        
        int i;
        for (i=0;nums[i]!=1;i++) {}
        
        long long gap=0;
        for (;i<nums.size();i++) {
            if (nums[i] != 1) gap++;
            else {
                ans = ans*(gap+1)%1000000007;
                gap = 0;
            }
            ans = ans%1000000007;
        }
        
        return ans;
    }
};