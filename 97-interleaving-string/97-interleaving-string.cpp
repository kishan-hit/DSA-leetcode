class Solution {
public:
    bool fun(string s1,string s2,string s3,int i,int j,int k,vector<vector<int>>&dp){
        if(i==0 && j==0 && k==0)
            return 1;
        if(i>0 && j>0 && dp[i][j]!=-1)
            return dp[i][j];
        if(i>0 && j>0 && k>0 && (s1[i-1]==s3[k-1]) && (s2[j-1]==s3[k-1]))
            return dp[i][j] = fun(s1,s2,s3,i-1,j,k-1,dp) || fun(s1,s2,s3,i,j-1,k-1,dp);
        else if(i>0 && k>0 && s3[k-1]==s1[i-1])
            return fun(s1,s2,s3,i-1,j,k-1,dp);
        else if(j>0 && k>0 && s3[k-1]==s2[j-1])
            return fun(s1,s2,s3,i,j-1,k-1,dp);
        return 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length(),n2=s2.length(),n3=s3.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return fun(s1,s2,s3,n1,n2,n3,dp);
    }
};