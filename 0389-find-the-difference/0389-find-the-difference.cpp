class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> x;
        for (char c:s) 
            x[c]++;

        for (char c:t){
            if (x.find(c) == x.end() || x[c] == 0) return c;
            x[c]--;
        }

        return '0';
    }
};