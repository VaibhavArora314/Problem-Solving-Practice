class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() <= 2) return false;

        vector<int> mn(nums);

        for (int i=1;i<mn.size();i++)
            mn[i] = min(mn[i],mn[i-1]);
        
        stack<int> s;
        for (int i=nums.size()-1;i>=0;i--) {
            while (!s.empty() && s.top() <= mn[i]) 
                s.pop();

            if (nums[i] == mn[i]) continue;

            if (!s.empty() && nums[i] > s.top()) 
                return true;

            s.push(nums[i]);
        }

        return false;
    }
};