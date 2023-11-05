class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int j=1,count=0;

        while (j < arr.size() && count < k) {
            if (arr[j] <= arr[0]) count++;
            else {
                arr[0] = arr[j];
                count = 1;
            }
            j++;
        }

        return arr[0];
    }
};