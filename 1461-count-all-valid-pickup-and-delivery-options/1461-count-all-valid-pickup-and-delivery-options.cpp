class Solution {
public:
    int countOrders(int n) {
        long long count = 1; // for 1 pickup delivery pair

        for (int i=2;i<=n;i++) // consider ith pickup delivery pair
            count = (count*(2*i-1)*i)%1000000007;

        return count;
    }
};


//  a  b  c  d   e
// 1  2  3  4  5   6
// 2*i-1 = 6
// if pickup at 1 -> 6 possiblities of delivery
// if pickup at 2 -> 5 possiblities of delivery
// if pickup at 3 -> 4 possiblities of delivery
// if pickup at 4 -> 3 possiblities of delivery
// if pickup at 5 -> 2 possiblities of delivery
// if pickup at 6 -> 1 possiblities of delivery
// total combinations = n*(n+1)/2 where n = 2*i-1
//                    = (2*i-1)*(2*i-1+1)/2 = (2*i-1)*i

// so in the above approach we one by one consider each pickup deliver pair and update total combinations