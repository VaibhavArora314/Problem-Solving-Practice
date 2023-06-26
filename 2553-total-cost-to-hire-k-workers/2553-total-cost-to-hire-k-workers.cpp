class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        int i=0,j=costs.size()-1;

        for (;i<candidates;i++) {pq.push({costs[i],i});}
        for (;j>=i && j>=costs.size()-candidates;j--) {pq.push({costs[j],j});}

        long long totalCost = pq.top().first;
        int last = pq.top().second;
        pq.pop();

        for (int a=0;a<k-1;a++) {
            if (i<=j) {
                if (last < i) {
                    pq.push({costs[i],i++});
                } else {
                    pq.push({costs[j],j--});
                }
            }

            totalCost += pq.top().first;
            last = pq.top().second;
            pq.pop();
        }

        return totalCost;
    }
};