class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int elem1,elem2,count1=0,count2=0;

        for (int num:nums) {
            if (elem1 == num) count1++;
            else if (elem2 == num) count2++;
            else if (count1 == 0) {elem1 = num;count1++;}
            else if (count2 == 0) {elem2 = num;count2++;}
            else {count1--;count2--;}
        }

        count1 = count2 = 0;
        for (int num:nums) {
            if (elem1 == num) count1++;
            if (elem2 == num) count2++;
        }

        int min = nums.size()/3;

        vector<int> ans;
        if (count1 > min) ans.push_back(elem1);
        if (count2 > min) ans.push_back(elem2);
        if (ans.size() == 2 && ans[0] < ans[1]) swap(ans[0],ans[1]);
        return ans;
    }
};