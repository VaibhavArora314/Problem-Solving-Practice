class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n = sentence.size();
        if (n < 26) return false;
        
        vector<int> count(26,0);
        for (int i=0;i<n;i++) {
            count[sentence[i]-'a']++;
        }
        
        for (auto x:count)
            if (x==0) return false;
        
        return true;
    }
};