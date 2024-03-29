class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans=0;

        for (int num:nums) {
            ans += m[num];
            m[num]++;
        }

        return ans;
    }
};