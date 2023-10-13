class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> m;
        vector<vector<string>> ans;

        for (string s:strs) {
            string copy(s);
            sort(copy.begin(),copy.end());

            if (m.find(copy) != m.end()) ans[m[copy]].push_back(s);
            else {
                ans.push_back({s});
                m[copy] = ans.size()-1;
            }
        }

        return ans;
    }
};