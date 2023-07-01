class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=nums[0],c2=nums[0],count1=0,count2=0;

        for (int num: nums) {
            if (c1 == num) count1++;
            else if (c2 == num) count2++;
            else if (count1 == 0) {c1 = num;count1++;}
            else if (count2 == 0) {c2 = num;count2++;}
            else {count1--;count2--;}
        }

        int min = nums.size()/3+1;
        int a = 0,b = 0;
        for (int num:nums) {
            if (num == c1) a++;
            if (num == c2) b++;
        }

        vector<int> ans;
        
        if (a>=min) ans.push_back(c1);
        if (b>=min && c1 != c2) ans.push_back(c2);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};