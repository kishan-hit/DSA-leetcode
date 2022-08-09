class Solution {
public:
    int fun(vector<vector<int>>&mat,int i,int j,int temp,vector<vector<int>>&dp){
        if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size())
            return 0;
        if(mat[i][j]>temp){
            if(dp[i][j])
                return dp[i][j];
            dp[i][j] = max(fun(mat,i+1,j,mat[i][j],dp)+1,max(fun(mat,i-1,j,mat[i][j],dp)+1,
                        max(fun(mat,i,j+1,mat[i][j],dp)+1,fun(mat,i,j-1,mat[i][j],dp)+1)));  
             return dp[i][j];
        }
       return 0;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int maxi = INT_MIN;
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        int res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi = max(maxi,fun(matrix,i,j,INT_MIN,dp));
            }
        }
        return maxi;
    }
};