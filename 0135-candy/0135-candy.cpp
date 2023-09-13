class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> dist(ratings.size(),1);

        for (int i=1;i<ratings.size();i++) {
            if (ratings[i] > ratings[i-1])
                dist[i] = dist[i-1]+1;
        }

        for (auto x:dist) cout<<x<<" ";
        cout<<endl;

        for (int i = ratings.size()-2;i>=0;i--) {
            if (ratings[i] > ratings[i+1])
                dist[i] = max(dist[i],dist[i+1]+1);
        }

        for (auto x:dist) cout<<x<<" ";
        cout<<endl;

        return accumulate(dist.begin(), dist.end(), 0);
    }
};