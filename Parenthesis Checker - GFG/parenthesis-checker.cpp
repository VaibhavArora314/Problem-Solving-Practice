//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    bool isOpening(char x) {
        return (x == '(' || x == '{' || x == '[');
    }
    bool matchPar(char a,char b) {
        if (a == '(' && b == ')') return true;
        if (a == '{' && b == '}') return true;
        if (a == '[' && b == ']') return true;
        
        return false;
    }
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x){
        stack<char> s;
        
        for (auto c:x) {
            if (isOpening(c)) s.push(c);
            else {
                if (s.empty()) return false;
                
                if (!matchPar(s.top(),c)) return false;
                s.pop();
            }
        }
        
        return s.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends