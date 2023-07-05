class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> count;
        
        int i=0,m=0;
        while (i<nums.size()) {
            if (nums[i] == 0) {
                count.push_back(0);
                i++;
                continue;
            }

            int c=0;
            while(i<nums.size() && nums[i] == 1) {
                i++; c++;
            }
            count.push_back(c);
        }

        if (count.size() == 1) m = max(m,count[0]-1);

        for (int i=1;i<count.size()-1;i++) {
            if (count[i] == 0 && count[i-1] + count[i+1] > m) 
                m = count[i-1] + count[i+1];
            else
                m = max(m,count[i]);
        }

        return m;
    }
};