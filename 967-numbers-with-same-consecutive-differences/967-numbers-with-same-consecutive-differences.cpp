class Solution {
    void helper(vector<int> &ans,int num, int last,int size,int k,int n) {
        if (n == size) {
            if (last != 0) ans.push_back(num);
            return;
        }
        
        for (int i=0;i<=9;i++) {
            if (abs(i-last) == k) helper(ans,i*pow(10,size)+num,i,size+1,k,n);
        }
        
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for (int i=0;i<=9;i++) {
            helper(ans,i,i,1,k,n);
        }
        return ans;
    }
};