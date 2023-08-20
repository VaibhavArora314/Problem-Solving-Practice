class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0,high=matrix.size()-1,mid;

        while (low <= high) {
            mid = (low+high)/2;

            if (matrix[mid][0] == target) return true;
            if (matrix[mid][0] > target) high = mid-1;
            else low = mid+1;
        }

        if (high == -1) return false;

        int xlow=0,xhigh=matrix[0].size()-1,xmid;
        while (xlow <= xhigh) {
            xmid = (xlow+xhigh)/2;

            if (matrix[high][xmid] == target) return true;
            if (matrix[high][xmid] > target) xhigh = xmid-1;
            else xlow = xmid+1;
        }

        return false;
    }
};