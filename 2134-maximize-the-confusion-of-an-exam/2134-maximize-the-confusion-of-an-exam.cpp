class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        if (answerKey.size() <= 1) return answerKey.size();
        int l=0,r=0,ans=1,tc=0,fc=0;
        
        if (answerKey[0] == 'T') tc++;
        else fc++;

        int i=1;
        while (i<answerKey.size()) {
            r++;
            if (answerKey[r] == 'T') tc++;
            else fc++;

            while (l<r && min(tc,fc) > k) {
                if (answerKey[l] == 'T') tc--;
                else fc--;

                l++;
            }

            ans = max(ans,tc+fc);

            i++;
        }
        return ans;
    }
};