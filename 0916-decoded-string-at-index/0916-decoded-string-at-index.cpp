class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long totalLength = 0;

        for (char c:s) {
            if (c >= '2' && c <= '9') totalLength *= c-'0';
            else totalLength++;
        }
        
        cout<<totalLength<<endl;

        int j = s.length()-1;
        while (j>=0) {
            cout<< s[j]<<" ";

            if (s[j] >= '2' && s[j] <= '9'){
                totalLength /= s[j]-'0';
                k %= totalLength;
                if (k == 0) k = totalLength;
            }
            else if (totalLength == k) return string(1,s[j]);
            else totalLength--;

            cout<<totalLength<<endl;

            j--;
        }

        return "0";
    }
};