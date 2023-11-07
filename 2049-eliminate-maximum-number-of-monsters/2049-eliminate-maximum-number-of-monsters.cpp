class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<float> arrivalTime;

        for (int i=0;i<n;i++)
            arrivalTime.push_back(dist[i]*1.0/speed[i]);
        
        sort(arrivalTime.begin(),arrivalTime.end());

        int c = 0;
        for (int i=0;i<n;i++) {
            // cout<<c<<" "<<arrivalTime[i]<<endl;
            if (arrivalTime[i] <= i) break;

            c++;
        }
        return c;
    }
};