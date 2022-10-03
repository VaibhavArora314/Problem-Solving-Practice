class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0,last=0;
        int i=1;
        while (i<colors.size()) {
            if (colors[last] == colors[i]) {
                ans+=min(neededTime[last],neededTime[i]);
                if (neededTime[last] < neededTime[i]) last = i;
            } else
                last = i;
            i++;
        }
        return ans;
    }
};