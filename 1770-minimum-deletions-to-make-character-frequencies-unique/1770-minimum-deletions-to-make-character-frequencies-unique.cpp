class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(),s.end());

        // cout << s <<endl;

        unordered_set<int> x;
        int ans=0;

        for (int i=0;i<s.length();i++) {
            int count=1;

            while (i+1 < s.length() && s[i+1] == s[i]) {
                count++;
                i++;
            }

            if (x.find(count) == x.end()) x.insert(count);
            else {
                int copy = count;
                count--;
                while (count > 0 && x.find(count) != x.end())
                    count--;
                ans+=copy-count;
                x.insert(count);
            }

            // cout<<s[i]<<" "<<count<<" "<<ans<<endl;
        }

        return ans;
    }
};