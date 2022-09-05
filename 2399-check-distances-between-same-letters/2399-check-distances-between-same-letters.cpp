class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<char,int> last;
        map<char,int>::iterator itr;
        for (int i=0;i<s.size();i++) {
            itr = last.find(s[i]);
            if (itr == last.end()) {
                last.insert({s[i],i});
            } else {
                if (distance[s[i] - 'a'] != i-itr->second-1) return false;
                itr->second = i;
            }
        }
        return true;
    }
};