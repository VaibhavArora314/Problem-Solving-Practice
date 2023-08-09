class Solution {
    int countPairs(vector<int>&nums,int limit) {
        int i=0,c=0;
        while (i<nums.size()-1) {
            if (nums[i+1] - nums[i] <= limit) {
                i++;
                c++;
            }
            i++;
        }
        return c;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());

        int low=0,high=nums[nums.size()-1]-nums[0];
        while (low<high) {
            int mid = (low+high)/2;
            int x=countPairs(nums,mid);

            if (x >= p)
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};
