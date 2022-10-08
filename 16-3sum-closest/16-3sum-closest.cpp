class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size(),closest=INT_MAX;
        for (int i=0;i<n-2;i++) {
            int l=i+1,r=n-1;
            while (l<r) {
                int sum = nums[i]+nums[l]+nums[r];
                if (abs(target - sum) < (closest == INT_MAX ? INT_MAX : abs(target - closest))) closest = sum;
                
                if (target == sum) return target;                
                if (target > sum) l++;
                else r--;
            }
        }
        return closest;
    }
};
