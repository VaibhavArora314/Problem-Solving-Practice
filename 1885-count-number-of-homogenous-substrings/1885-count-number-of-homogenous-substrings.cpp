class Solution {
    int mod = 1000000007;
public:
    int countHomogenous(string s) {
        int ans = 0;

        char last = '1';
        int count = 0;

        for (char c:s) {
            if (last == c)
                count = (count+1)%mod;
            else {
                count = 1;
                last = c;
            }
            ans = (ans + count)%mod;
        }

        return ans;
    }
};