class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;

        for (int num:nums) m[num]++;

        priority_queue<pair<int,int>> pq;
        for (auto itr=m.begin();itr!=m.end();itr++)
            pq.push({itr->second,itr->first});
        
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};