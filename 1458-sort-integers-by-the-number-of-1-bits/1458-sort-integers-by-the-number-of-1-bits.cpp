int getBitCount(int x) {
    int c = 0;
    while (x) {
        if (x&1) c++;
        x = x>>1;
    }
    return c;
}

bool compare(const int a,const int b) {
    int countA = getBitCount(a), countB = getBitCount(b);

    if (countA == countB) return a < b;
    return countA < countB;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};