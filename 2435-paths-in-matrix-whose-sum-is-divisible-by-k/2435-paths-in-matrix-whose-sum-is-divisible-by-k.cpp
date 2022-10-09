class Solution {
public:
    int mod = 1e9+7;
    int f(int i,int j,vector<vector<int>>& grid, int k,int sum,vector<vector<vector<int>>>&dp) {
        if(i<0 || j<0)
            return 0;
        if(dp[i][j][sum%k]!=-1)
            return dp[i][j][sum%k];
        if(i==0 && j==0){
            sum += grid[i][j];
            if(sum % k ==0)
                return 1;
            return 0;
        }
        int up = f(i-1,j,grid,k,sum+grid[i][j],dp) % mod;
        int left = f(i,j-1,grid,k,sum+grid[i][j],dp) % mod;
        return dp[i][j][sum%k]=((up+left)%mod);
       
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));
        int ans = f(n-1,m-1,grid,k,0,dp);
        return ans%mod;
    }
};