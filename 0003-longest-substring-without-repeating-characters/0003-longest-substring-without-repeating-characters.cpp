class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;

        int l=0,r=0;
        unordered_map<char,int> m;
        m[s[0]]++;

        int ans = 1;
        for (int i=1;i<s.length();i++) {
            if (m[s[i]] == 0) m[s[i]]++;
            else {
                while (l<=r && m[s[i]] >= 1) {
                    m[s[l]]--;
                    l++;
                }
                m[s[i]]++;
            }

            r++;
            if (ans < r-l+1) ans = r-l+1;
        }

        return ans;
    }
};