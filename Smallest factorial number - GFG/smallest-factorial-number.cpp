//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
        bool isValid(int x,int n) {
            int cf=0,ct=0,temp=x;
            
            while (temp > 0) {
                temp = temp/5;
                cf += temp;
                
                if (cf>=n) break;
            }
            
            while (x>0) {
                x = x/2;
                ct += x;
                
                if (ct>=n) break;
            }
            
            return (cf >= n && ct >= n);
        }
    public:
        int findNum(int n) {
            int low=0,high=INT_MAX,mid,ans;
            
            while (low<=high) {
                mid = (low+high)/2;
                
                if (isValid(mid,n)) {
                    ans=mid;
                    high=mid-1;
                } else
                    low = mid+1;
            }
            
            return ans;
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends