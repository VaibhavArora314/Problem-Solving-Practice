class Solution {
public:
 vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        set<pair<int,int>> visited;

        pq.push({nums1[0]+nums2[0],{0,0}});
        // visited.insert({0,0});

        for (int i=0;i<k && !pq.empty();i++) {
            pair<int,pair<int,int>> t = pq.top();
            int a =t.second.first,b=t.second.second;

            ans.push_back({nums1[a],nums2[b]});

            if (b+1 < nums2.size() && visited.find({a,b+1}) == visited.end()) {pq.push({nums1[a]+nums2[b+1],{a,b+1}});visited.insert({a,b+1});}
            if (a+1 < nums1.size() && visited.find({a+1,b}) == visited.end()) {pq.push({nums1[a+1]+nums2[b],{a+1,b}});visited.insert({a+1,b});}

            pq.pop();
        }

        return ans;
    }
};