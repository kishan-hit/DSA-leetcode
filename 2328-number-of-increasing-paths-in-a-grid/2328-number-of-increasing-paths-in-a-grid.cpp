class Solution {
public:
    int m,n;
    int mod=1e9+7;
    int solve(vector<vector<int>>& grid,int i,int j,int val,vector<vector<int>> &dp){
        if(i<0 || i>=m || j<0 || j>=n)
            return 0;
        if(grid[i][j]<=val)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=(1+solve(grid,i+1,j,grid[i][j],dp)%mod)%mod;
        ans=(ans%mod+solve(grid,i-1,j,grid[i][j],dp)%mod)%mod;
        ans=(ans%mod+solve(grid,i,j+1,grid[i][j],dp)%mod)%mod;
        ans=(ans%mod+solve(grid,i,j-1,grid[i][j],dp)%mod)%mod;
        return dp[i][j]=ans;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        int ans=0;
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                ans=(ans%mod+solve(grid,i,j,-1,dp)%mod)%mod;
        }
        return ans;
    }
};