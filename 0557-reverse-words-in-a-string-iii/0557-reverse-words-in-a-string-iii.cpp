class Solution {
public:
    string reverseWords(string s) {
        vector<string> splits;
        int prev=0;
        for (int i=0;i<s.length();i++) {
            if (s[i] == ' ') {
                if (prev < i) splits.push_back(s.substr(prev,i-prev));
                prev = i+1;
            }
        }
        if (s.size() > prev) splits.push_back(s.substr(prev,s.size()-prev));
        string ans = "";
        for (int i=0;i<splits.size();i++) {
            for (int j=splits[i].size()-1;j>=0;j--) ans += splits[i][j];
            if (i < splits.size()-1) ans += ' ';
        }
        return ans;
    }
};