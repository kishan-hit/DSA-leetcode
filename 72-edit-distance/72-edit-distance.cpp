class Solution {
public:
    int fun(string word1,string word2,int i,int j,vector<vector<int>>&dp){
        if(i==0)
            return j;
        if(j==0)
            return i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(word1[i-1]==word2[j-1])
            return dp[i][j] = fun(word1,word2,i-1,j-1,dp);
        return dp[i][j] = 1 + min(fun(word1,word2,i-1,j-1,dp),min(fun(word1,word2,i,j-1,dp),fun(word1,word2,i-1,j,dp)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return fun(word1,word2,n,m,dp);
    }
};