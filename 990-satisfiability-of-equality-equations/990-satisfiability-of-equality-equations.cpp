class Solution {
    int set[27];
    int unionFind(int x) {
        if (x == set[x]) return x;
        return unionFind(set[x]);
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i=1;i<27;i++) set[i] = i;
        
        for (string e: equations) {
            if (e[1] == '=') set[unionFind(e[0]-'a')] = unionFind(e[3]-'a');
        }
        
        for (string e: equations) {
            if (e[1] == '!' && unionFind(e[0]-'a') == unionFind(e[3] - 'a')) return false;
        }
        return true;
    }
};