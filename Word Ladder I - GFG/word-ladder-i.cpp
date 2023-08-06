//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int bfs(string t,queue<string> q,unordered_map<string,vector<string>>& m,set<string>& visited) {
        if (q.empty()) return 0;
        int ans = INT_MAX;
        queue<string> next;
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            if (s == t) return 1;
            
            for (int i=0;i<m[s].size();i++) {
                if (visited.find(m[s][i]) == visited.end()) {
                    visited.insert(m[s][i]);
                    next.push(m[s][i]);
                }
            }
        }
        
        int x=bfs(t,next,m,visited);
        if (x>0)x++;
        return x;
    }
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> m;
        bool x = false;
        for (int i=0;i<wordList.size();i++) {
            if (wordList[i] == startWord) x=true;
            for (int j=i+1;j<wordList.size();j++) {
                int c=0;
                for (int k=0;k<wordList[0].size();k++) {
                    if (wordList[i][k] != wordList[j][k]) c++;
                    if (c>1) break;
                }
                if (c <= 1) {
                    m[wordList[i]].push_back(wordList[j]);
                    m[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        
        if (!x) {
            for (int j=0;j<wordList.size();j++) {
                int c=0;
                for (int k=0;k<wordList[0].size();k++) {
                    if (startWord[k] != wordList[j][k]) c++;
                    if (c>1) break;
                }
                if (c <= 1) {
                    m[startWord].push_back(wordList[j]);
                    m[wordList[j]].push_back(startWord);
                }
            }
        }
        
        set<string> visited;
        queue<string> q;
        q.push(startWord);
        
        return bfs(targetWord,q,m,visited);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends