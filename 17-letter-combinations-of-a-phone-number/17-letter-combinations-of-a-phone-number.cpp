class Solution {
    vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void helper(vector<string> &ans, int cur,string digits,string perm) {
        if (cur == digits.size()) {
            ans.push_back(perm);
            return;
        }

        for (auto x:mapping[digits[cur] - '0']) {
            helper(ans,cur+1,digits,perm + x);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        
        vector<string> ans;
        helper(ans,0,digits,"");
        return ans;
    }
};