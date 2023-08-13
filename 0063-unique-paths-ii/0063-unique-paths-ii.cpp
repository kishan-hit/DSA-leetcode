class Solution {
public:
    // int fun(vector<vector<int>>&nums,int i,int j,vector<vector<int>>&dp){
    //     if(i<0 || j<0)
    //         return 0;
    //     if(i==0 && j==0)
    //         return 1;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     int left=0,up=0;
    //     if(i>=1 && nums[i-1][j]!=1)
    //         left = fun(nums,i-1,j,dp);
    //     if(j>=1 && nums[i][j-1]!=1)
    //         up = fun(nums,i,j-1,dp);
    //     return dp[i][j] = (up+left);
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(),m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        if(obstacleGrid[0][0]==1)
            return 0;
        dp[0][0] = 1;
        for(int i=1;i<n;i++)
            if(obstacleGrid[i][0]!=1)
                dp[i][0] = dp[i-1][0];
        for(int j=1;j<m;j++)
            if(obstacleGrid[0][j]!=1)
                dp[0][j] = dp[0][j-1];
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                if(obstacleGrid[i][j]==0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];   
        return dp[n-1][m-1];
    }
};