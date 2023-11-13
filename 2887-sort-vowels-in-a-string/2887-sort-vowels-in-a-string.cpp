class Solution {
    bool isVowel(char x) {
        return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U');
    }
public:
    string sortVowels(string s) {
        vector<char> v;

        for (char c:s) {
            if (isVowel(c)) 
                v.push_back(c);
        }

        sort(v.begin(),v.end());

        string ans = "";
        for (int i=0,j=0;i<s.length();i++) {
            if (isVowel(s[i]))
                ans += v[j++];
            else
                ans += s[i];
        }

        return ans;
    }
};