class Solution {
public:
    int fun(string text1,string text2,int i,int j,vector<vector<int>>&dp){
        if(i==0 || j==0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(text1[i-1]==text2[j-1])
            return dp[i][j] = 1 + fun(text1,text2,i-1,j-1,dp);
        return dp[i][j] = max(fun(text1,text2,i-1,j,dp),fun(text1,text2,i,j-1,dp));
    }
    int minDistance(string word1, string word2) {
        int n1=word1.length(),n2=word2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return (n1 + n2 - 2*fun(word1,word2,n1,n2,dp));
    }
};