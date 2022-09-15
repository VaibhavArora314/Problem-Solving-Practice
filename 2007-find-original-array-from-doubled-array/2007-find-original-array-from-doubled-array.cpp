class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size()%2 == 1 || changed.size() == 0) return {};
        
        sort(changed.begin(),changed.end());
        
        multiset<int> rec;
        multiset<int>::iterator itr;
        vector<int> ans;
        rec.insert(changed[0]);
        int i=1;
        while (i<changed.size()) {
            itr = rec.find(changed[i]/2);
            if (itr == rec.end() || changed[i]%2 == 1) {
                rec.insert(changed[i++]);
            } else {
                ans.push_back(*itr);
                rec.erase(itr);
                i++;
            }
        }
        if (rec.size() != 0) return {};
        return ans;
    }
};