class Solution {
    int find(int a,unordered_map<int,pair<bool,int>>& p) {
        if (p[a].first) return a;
        p[a].second = find(p[a].second,p);
        return p[a].second;
    }
    void Union(int a,int b,unordered_map<int,pair<bool,int>>& p) {
        int fa = find(a,p),fb = find(b,p);

        if (fa == fb) return;
        if (p[fa].second >= p[fb].second) {
            p[fa].second += p[fb].second;
            p[fb] = {0,fa};
        } else {
            p[fb].second += p[fa].second;
            p[fa] = {0,fb};
        }
    }
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,pair<bool,int>> p;

        for (int i=0;i<nums.size();i++) {
            if (p.find(nums[i]) != p.end()) continue;

            p[nums[i]] = {1,1};

            if (p.find(nums[i]+1) != p.end())
                Union(nums[i],nums[i]+1,p);
            if (p.find(nums[i]-1) != p.end())
                Union(nums[i],nums[i]-1,p);
        }

        int ans = 0;
        for (auto itr=p.begin();itr != p.end();itr++) {
            cout<<itr->first<<" "<<itr->second.first<<" "<<itr->second.second<<endl;
            if (itr->second.first) 
                ans = max(ans,abs(itr->second.second));
        }

        return ans;
    }
};