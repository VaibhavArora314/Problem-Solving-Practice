class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> answer;
        int sum=0;
        for (int x:nums) {
            if (x%2 == 0)
                sum += x;
        }
        
        for (auto query:queries) {
            int index = query[1], val = query[0];
            if (nums[index]%2 == 0) sum -= nums[index];
            nums[index] += val;
            if (nums[index]%2 == 0) sum += nums[index];
            answer.push_back(sum);
        }
        
        return answer;
    }
};