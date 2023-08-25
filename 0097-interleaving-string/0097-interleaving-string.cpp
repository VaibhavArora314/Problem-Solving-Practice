class Solution {
    bool helper(string s1,string s2,string s3,map<vector<int>,bool> &mem,int i=0,int j=0,int k=0) {
        bool ret=false;

        if (mem.find({i,j,k}) != mem.end()) return mem[{i,j,k}];

        if (k == s3.length()) {
            return (i == s1.length() && j == s2.length());
        }

        if (i<s1.length() && s1[i] == s3[k]) ret = ret || helper(s1,s2,s3,mem,i+1,j,k+1);
        if (j<s2.length() && s2[j] == s3[k]) ret = ret || helper(s1,s2,s3,mem,i,j+1,k+1);

        mem[{i,j,k}] = ret;

        return ret;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        map<vector<int>,bool> mem;

        return helper(s1,s2,s3,mem);
    }
};