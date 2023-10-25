class Solution {
    int helper(int curN,int k) {
        if (curN == 0) return 0;

        int prevK = k/2;
        int prevV = helper(curN-1,prevK);
        if (k == prevK*2) return prevV;
        return prevV == 1 ? 0 : 1;
    }
public:
    int kthGrammar(int n, int k) {
        return helper(n-1,k-1);
    }
};