class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        int leftPartitionLength = (totalLength+1)/2; // len of left partition of merged sorted array

        int low,high,m1,m2;
        high = (nums1.size() >= leftPartitionLength) ? leftPartitionLength : nums1.size();
        low = (nums2.size() >= leftPartitionLength) ? 0 : leftPartitionLength - nums2.size();

        while (low <= high) {
            m1 = (low+high)/2;
            m2 = leftPartitionLength - m1;

            int x1 = (m1 > 0) ? nums1[m1-1] : INT_MIN,x2 = (m2 > 0) ? nums2[m2-1] : INT_MIN;
            int y1 = (m1 == nums1.size()) ? INT_MAX : nums1[m1],y2 = (m2 == nums2.size()) ? INT_MAX : nums2[m2];

            if (x1 <= y2 && x2 <= y1) {
                if (totalLength%2 == 0) return (max(x1,x2)+min(y1,y2))/2.0;
                return max(x1,x2);
            } else if (x1 > y2) high = m1-1;
            else low = m1+1;
        }

        return 0;
    }
};