class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        
        int start = 0,end = nums.size()-1,mid;
        while (start<=end) {
            mid = (start+end)/2;
            if (target>nums[mid])
                start = mid+1;
            else if (target<nums[mid])
                end = mid-1;
            else {
                end = mid-1;
                res[0] = mid;
            }
        }
        
        start = 0,end = nums.size()-1;
        while (start<=end) {
            mid = (start+end)/2;
            if (target>nums[mid])
                start = mid+1;
            else if (target<nums[mid])
                end = mid-1;
            else {
                start = mid+1;
                res[1] = mid;
            }
        }
        
        return res;
    }
};