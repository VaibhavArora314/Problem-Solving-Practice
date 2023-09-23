bool compareStringLength(const std::string& str1, const std::string& str2) {
    return str1.size() < str2.size();
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> dp;
        for (auto x:words) dp[x] = 1;

        sort(words.begin(),words.end(),compareStringLength);

        int ans = 1;
        for (int i=words.size()-1;i>=0;i--) {
            if (dp[words[i]] > ans) ans = dp[words[i]];

            for (int j=0;j<words[i].length();j++) {
                string temp = words[i].substr(0,j)+words[i].substr(j+1,words[i].size()-j+1);

                if (dp[temp] > 0)
                    dp[temp] = max(dp[temp],dp[words[i]]+1);
            }
        }

        return ans;
    }
};