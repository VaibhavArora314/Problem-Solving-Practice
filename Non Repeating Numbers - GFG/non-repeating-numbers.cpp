//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) {
        int x=0;
        for (int i=0;i<nums.size();i++) x = (x^nums[i]);
        
        int rightMost = (x & ~(x-1));
        int a=0,b=0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] & rightMost) a = (a^nums[i]);
            else b = (b^nums[i]);
        }
        
        return {min(a,b),max(a,b)};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends