class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> m;
        for (int p:people) m[p] = 0;
        
        multiset<int> start,end;
        for (auto f:flowers) {
            start.insert(f[0]);
            end.insert(f[1]);
        }

        multiset<int>::iterator s=start.begin(),e=end.begin();
        for (auto i=m.begin();i!=m.end();i++) {
            auto temp = i;
            temp--;
            if (i != m.begin()) i->second = temp->second;

            while (s != start.end() && *s <= i->first) {
                i->second++;
                s++;
            }
            while (e != end.end() && *e < i->first) {
                i->second--;
                e++;
            }

            // cout<<prefix[i]<<" ";
        }

        vector<int> ans;
        for (int p:people) ans.push_back(m[p]);
        return ans;
    }
};