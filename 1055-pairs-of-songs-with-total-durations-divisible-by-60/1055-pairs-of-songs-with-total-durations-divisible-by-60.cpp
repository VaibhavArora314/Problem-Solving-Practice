class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> freq(60,0);
        int count=0;

        for (int t:time) {
            count += freq[60-(t%60==0 ? 60 : t%60)];

            freq[t%60]++;
        }

        return count;
    }
};