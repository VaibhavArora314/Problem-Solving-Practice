class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        int tests = 1;
        while (tests < buckets) {
            tests *= minutesToTest/minutesToDie + 1;
            pigs++;
        }
        return pigs;
    }
};