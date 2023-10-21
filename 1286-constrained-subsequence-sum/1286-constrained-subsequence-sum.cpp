class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        if (*max_element(nums.begin(),nums.end()) < 0)
            return -1;
        
        vector<int> dp(nums.size(),0);
        priority_queue<pair<int,int>> pq;

        for (int i=0;i<dp.size();i++) {
            dp[i] = nums[i];

            while (!pq.empty() && pq.top().second < i-k)
                pq.pop();

            if (!pq.empty() && pq.top().first > 0) dp[i] += pq.top().first;
            pq.push({dp[i],i});

            cout<<dp[i]<<" ";
        }

        return *max_element(dp.begin(),dp.end());
    }
};