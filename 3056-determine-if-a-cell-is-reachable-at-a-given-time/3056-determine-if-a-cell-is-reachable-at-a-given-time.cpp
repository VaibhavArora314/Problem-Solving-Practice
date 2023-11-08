class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy) return t != 1;

        int minTime = max(abs(sx-fx),abs(sy-fy));
        return minTime <= t; 
    }
};