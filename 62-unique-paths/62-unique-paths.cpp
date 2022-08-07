class Solution {
public:
    int fun(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j] = fun(i-1,j,dp) + fun(i,j-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0)
                    dp[i][j] = 1;
                else{
                    int cnt=0;
                    if(i-1>=0)
                        cnt += dp[i-1][j];
                    if(j-1>=0)
                        cnt += dp[i][j-1];
                    dp[i][j] = cnt;
                }
            }
        }
        return dp[m-1][n-1];
    }
};