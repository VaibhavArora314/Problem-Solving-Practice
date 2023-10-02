class Solution {
public:
    bool winnerOfGame(string colors) {
        int i=0,countA=0,countB=0;
        
        while (i<colors.length()) {
            int count = 1;
            if (colors[i] == 'A') {
                i++;
                while (i < colors.length() && colors[i] == colors[i-1]) {count++;i++;}
                if (count>2) countA += count-2;
            } else {
                i++;
                while (i < colors.length() && colors[i] == colors[i-1]) {count++;i++;}
                if (count>2) countB += count-2;
            }
        }

        cout<<countA<<" "<<countB<<endl;

        return countA > countB;
    }
};