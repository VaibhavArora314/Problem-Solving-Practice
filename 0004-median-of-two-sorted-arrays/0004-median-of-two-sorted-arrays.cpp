class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2= nums2.size();

        if (n1 == 0) return (n2&1) ? nums2[n2/2] : (nums2[n2/2]+nums2[n2/2-1])/2.0;
        if (n2 == 0) return (n1&1) ? nums1[n1/2] : (nums1[n1/2]+nums1[n1/2-1])/2.0;

        int total = n1+n2;
        int low,high,mid,eleOnLeft = total/2;

        if (eleOnLeft >= nums2.size()) low = eleOnLeft-nums2.size();
        else low = 0;

        if (eleOnLeft >= nums1.size()) high = n1;
        else high = eleOnLeft;

        // cout<<low<<" "<<high<<endl;

        while (low <= high) {
            mid = (low+high)/2;
            int mid2 = eleOnLeft - mid;

            int l1 = mid > 0 ? nums1[mid-1] : INT_MIN,
                l2 = mid2 > 0 ? nums2[mid2-1] : INT_MIN,
                r1 = mid < n1 ? nums1[mid] : INT_MAX,
                r2 = mid2 < n2 ? nums2[mid2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1)
                return (total&1) == 1 ? min(r1,r2)*1.0 : (min(r1,r2)+max(l1,l2))/2.0;
            if (l1 > r2)
                high = mid-1;
            else
                low = mid+1;
        }

        return -1;
    }
};