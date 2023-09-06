class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),trappedWater=0;

        if (n <= 2) return 0;

        vector<int> maxOnLeft(n),maxOnRight(n);

        maxOnRight[n-1] = height[n-1];
        for (int i=n-2;i>=0;i--)
            maxOnRight[i] = max(height[i],maxOnRight[i+1]);
        
        maxOnLeft[0] = height[0];
        for (int i=1;i<n;i++) {
            maxOnLeft[i] = max(height[i],maxOnLeft[i-1]);
            trappedWater += min(maxOnLeft[i],maxOnRight[i]) - height[i];
        }

        return trappedWater;
    }
};