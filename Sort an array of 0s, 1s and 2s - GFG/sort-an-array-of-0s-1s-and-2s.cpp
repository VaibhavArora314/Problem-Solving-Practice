//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int b[3]={0};
        for (int i=0;i<n;i++) {
            b[a[i]]++;
        }
        int i=0,j=0;
        while (i<n) {
            if (b[j] == 0) {
                j++;
                continue;
            }
            if (j == 3) return;
            a[i++] = j;
            b[j]--;
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