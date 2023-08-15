//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    double calculateDistance(double x1, double y1, double x2, double y2) {
        return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }

    double calculateCost(double x,double y,vector<pair<int,int>> &p) {
        double totalCost=0;
        for (int i=0;i<p.size();i++)
            totalCost += calculateDistance(x,y,p[i].first,p[i].second);
        return totalCost;
    }

    double calulateY(tuple<int, int, int> l, double x) {
        return -1.0 * (get<0>(l) * x + get<2>(l)) / get<1>(l);
    }

    public:
    double findOptimumCost(tuple<int,int,int>l, vector<pair<int,int>>p, int n){
	   double xhigh = 1000, xlow = -1000,mid1,mid2,eps=0.000001,y,d1,d2;
	   
	   while (xhigh - xlow > eps) {
	       mid1 = xlow + (xhigh-xlow)/3;
	       mid2 = xlow + 2*(xhigh-xlow)/3;
	       
	       d1 = calculateCost(mid1,calulateY(l,mid1),p);
	       d2 = calculateCost(mid2,calulateY(l,mid2),p);
	       
	       //cout<<xhigh<<" "<<xlow<<" "<<mid1<<" "<<d1<<" "<<mid2<<" "<<d2<<endl;
	       
           if (d1<d2) xhigh = mid2;
           else if (d1>d2) xlow = mid1;
           else {
               xhigh = mid2;
               xlow = mid1;
           }
	   }
	   
	   return calculateCost(xlow,calulateY(l,xlow),p);
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    tuple<int,int,int>line;
	    int a, b, c;
	    cin >> a >> b >> c;
	    line = make_tuple(a, b, c);
	    int n;
	    cin >> n;
	    vector<pair<int,int>>points;
	    for(int i = 0 ; i < n; i++){
	        int x, y;
	        cin >> x >> y;
	        points.push_back({x, y});
	    }

	    Solution ob;
	    double ans = ob.findOptimumCost(line, points, n);

	    cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}

// } Driver Code Ends