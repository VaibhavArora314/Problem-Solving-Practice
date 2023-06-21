class Solution {
    long long findCost(vector<int>& nums,vector<int>& cost, int x) {
        long long totalCost = 0,temp;
        for (int i=0;i<nums.size();i++) {
            temp = abs(nums[i]-x);
            totalCost += temp*cost[i];
        }
        return totalCost;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int l=*min_element(nums.begin(), nums.end()),
            r=*max_element(nums.begin(), nums.end()),
            mid;
        long long cost1,cost2;
        while (l<r) {
            mid=(l+r)/2;
            cost1 = findCost(nums,cost,mid);
            cost2 = findCost(nums,cost,mid+1);

            if (cost1 <= cost2)
                r = mid;
            else
                l = mid+1;
        }

        return findCost(nums,cost,l);
    }
};