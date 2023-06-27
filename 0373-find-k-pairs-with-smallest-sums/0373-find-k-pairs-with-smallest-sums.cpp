class Solution {
public:
 vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        map<vector<int>,int> m;

        pq.push({nums1[0]+nums2[0],{0,0}});

        for (int i=0;i<k && !pq.empty();i++) {
            pair<int,pair<int,int>> t = pq.top();
            int b =t.second.first,a=t.second.second;

            ans.push_back({nums1[a],nums2[b]});

            if (b+1 < nums2.size() && m.find({b+1,a}) == m.end()) {pq.push({nums1[a]+nums2[b+1],{b+1,a}});m[{b+1,a}] = 1;}
            if (a+1 < nums1.size() && m.find({b,a+1}) == m.end()) {pq.push({nums1[a+1]+nums2[b],{b,a+1}});m[{b,a+1}] = 1;}

            pq.pop();
        }

        return ans;
    }
};