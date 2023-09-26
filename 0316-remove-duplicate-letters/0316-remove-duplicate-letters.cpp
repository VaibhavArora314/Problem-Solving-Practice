class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> m;
        for (char c:s) m[c]++;

        stack<char> stk;
        long long mask = 0;
        for (char c:s) {
            int isPresent = (mask & (1<<(c-'a')));
            if (isPresent > 0) {
                cout<<isPresent<<endl;
                m[c]--;
                continue;
            }
            
            while (!stk.empty() && stk.top() > c && m[stk.top()]){
                mask = (mask ^ (1<<(stk.top()-'a')));
                stk.pop();
            }
            stk.push(c);
            mask = (mask | 1<<(c-'a'));
            m[c]--;

            cout<<mask<<" "<<stk.top()<<" "<<stk.size()<<endl;
        }

        string ans="";
        while (!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};