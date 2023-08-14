class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0,low=0,high=height.size()-1,currentArea;

        while (low < high) {
            currentArea = (high-low)*min(height[low],height[high]);
            area = max(area,currentArea);

            if (height[low]<=height[high]) low++;
            else high--;
        }

        return area;
    }
};