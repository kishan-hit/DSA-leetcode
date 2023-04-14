class Solution {
public:
    int fun(string &s,string &t,int i,int j,vector<vector<int>>&vec){
        int res;
        if(i<=0 || j<=0)
            return 0;
        if(vec[i][j]!=-1)
            return vec[i][j];
        if(s[i-1]==t[j-1])
           return vec[i][j] = 1 + fun(s,t,i-1,j-1,vec);
        return vec[i][j] = max(fun(s,t,i-1,j,vec),fun(s,t,i,j-1,vec));
    }
    int longestPalindromeSubseq(string s) {
        string temp = s;
        reverse(temp.begin(),temp.end());
        int n = s.length();
        vector<vector<int>> vec(n+1,vector<int> (n+1,-1));
        return fun(s,temp,n,n,vec);
    }
};