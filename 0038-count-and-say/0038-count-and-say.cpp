class Solution {
    vector<pair<int,int>> convertStringToMap(string s) {
        vector<pair<int,int>> map;
        for (int i=0;i<s.size();i++) {
            if (map.size() == 0 || map[map.size()-1].first != s[i]-'0')
                map.push_back({s[i]-'0',1});
            else {
                map[map.size()-1].second++;
            }
        }
        return map;
    }
    string convertMapToString(vector<pair<int,int>> map) {
        string s;
        for (auto x:map) {
            s+=to_string(x.second)+to_string(x.first);
        }
        return s;
    }
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        
        string ans =  convertMapToString(convertStringToMap(countAndSay(n-1)));
        
        return ans;
    }
};