class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(sx-fx),dy=abs(sy-fy);

        int minTime = max(dx,dy);
        
        if (t < minTime) return false;
        if (minTime == 0) return (t != 1);

        return true;
    }
};

// 1 1 1 1 3 -> true