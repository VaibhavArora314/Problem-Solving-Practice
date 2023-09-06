class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> m;
        int count=0;

        for (int t:time) {
            if (m[60-t%60] > 0) count+=m[60-t%60];

            m[t%60 == 0 ? 60 : t%60]++;
        }

        return count;
    }
};