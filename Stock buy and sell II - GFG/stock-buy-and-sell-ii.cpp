//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        int i=0,maxProfit=0;
        while (i<n) {
            while (i < n-1 && prices[i+1] <= prices[i]) i++;
            
            if (i == n-1) break;
            int buy = i;
            
            while (i<n-1 && prices[i+1] >= prices[i]) i++;
            int sell = i;
            
            if (prices[sell] > prices[buy]) maxProfit += prices[sell] - prices[buy];
            
            // cout<<prices[sell]<<" "<<prices[buy]<<" "<<maxProfit<<endl;
            
            i++;
        }
        return maxProfit;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends