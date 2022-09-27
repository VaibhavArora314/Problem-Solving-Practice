class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> pos;
        vector<char> symbols;
        pos.push_back(-1);
        symbols.push_back('L');
        
        for (int i=0;i<n;i++) {
            if (dominoes[i] != '.') {
                pos.push_back(i);
                symbols.push_back(dominoes[i]);
            }
        }
        
        pos.push_back(n);
        symbols.push_back('R');
        
        for (int i=0;i<pos.size()-1;i++) {
            int left = pos[i], right = pos[i+1];
            
            if (symbols[i] == symbols[i+1]) {
                for (int k=left+1;k<right;k++) {
                    dominoes[k] = symbols[i];
                }
            } else if (symbols[i] > symbols[i+1]) { //R__L
                int l = left + 1, r = right - 1;
                 while (l < r) {
                     dominoes[l++] = symbols[i];
                     dominoes[r--] = symbols[i+1];
                 }
            }
            // else L__R
        }
        
        return dominoes;
    }
};