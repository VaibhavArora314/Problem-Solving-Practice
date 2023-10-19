class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.length()-1,j=t.length()-1;
        
        while (i>=0 && j>=0) {
            if (s[i] == '#') {
                int k=i-1,c=1;
                while (k>=0 && c>0) {
                    if (s[k] == '#') c++;
                    else c--;

                    k--;
                }
                i=k;
            } else if (t[j] == '#') {
                int k=j-1,c=1;
                while (k>=0 && c>0) {
                    if (t[k] == '#') c++;
                    else c--;
                    
                    k--;
                }
                j=k;
            } else {
                if (s[i] != t[j]) return false;
                i--;
                j--;
            }

            cout<<i<<" "<<j<<endl;
        }

        if (i < 0) {
            int c = 0;
            while (j >= 0) {
                if (t[j] == '#') c--;
                else c++;

                if (c > 0) return false;
                j--;
            }
        }

        if (j < 0) {
            int c = 0;
            while (i >= 0) {
                if (s[i] == '#') c--;
                else c++;

                if (c > 0) return false;
                i--;
            }
        }

        return true;
    }
};