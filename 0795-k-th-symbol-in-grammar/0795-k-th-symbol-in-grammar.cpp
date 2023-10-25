class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;

        int prevK = (k+1)/2;
        int prevV = kthGrammar(n-1,prevK);
        if (k == prevK*2-1) return prevV;
        return prevV == 1 ? 0 : 1;
    }
};