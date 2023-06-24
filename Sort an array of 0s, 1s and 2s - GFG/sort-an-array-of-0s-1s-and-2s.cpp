//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int zeros=0,twos=n-1,cur=0;
        
        while (cur <= twos) {
            switch (a[cur]) {
                case 0: {
                    swap(a[cur++],a[zeros++]);
                    break;
                }
                case 1: {
                    cur++;
                    break;
                }
                case 2: {
                    swap(a[cur],a[twos--]);
                    break;
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends