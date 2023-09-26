class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> m;
        for (char c:s) m[c]++;

        stack<char> stk;
        vector<bool> inStack(26,false);
        for (char c:s) {
            if (inStack[c-'a']) {
                m[c]--;
                continue;
            }
            
            while (!stk.empty() && stk.top() > c && m[stk.top()] >= 1){
                inStack[stk.top()-'a'] = false;
                stk.pop();
            }
            stk.push(c);
            inStack[c-'a'] = true;
            m[c]--;
        }

        string ans="";
        while (!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};