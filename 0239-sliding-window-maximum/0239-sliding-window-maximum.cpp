class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;

        for (int i=0;i<k;i++) pq.push({nums[i],i});

        ans.push_back(pq.top().first);

        for (int l=1,r=k;r<nums.size();l++,r++) {
            pq.push({nums[r],r});

            while (pq.top().second < l) {
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};