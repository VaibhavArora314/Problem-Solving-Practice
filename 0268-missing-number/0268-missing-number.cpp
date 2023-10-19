class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int b = 0;
        for (int i=1;i<=nums.size();i++) b = (b^i);
        for (int num:nums) b = (b^num);
        return b;
    }
};