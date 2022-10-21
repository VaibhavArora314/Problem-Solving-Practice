class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> hash;
        map<int,int>::iterator itr;
        for (int i=0;i<nums.size();i++) {
            itr = hash.find(nums[i]);
            if (itr == hash.end()) hash.insert({nums[i],i});
            else {
                if (i-itr->second <= k) return true;
                itr->second = i;
            }
        }
        return false;
    }
};