class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m));
        for(int j=0;j<m;j++)
            dp[0][j] = matrix[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up = matrix[i][j],left = matrix[i][j],right = matrix[i][j];
                up += dp[i-1][j];
                if(j-1>=0)
                    left += dp[i-1][j-1];
                else
                    left = 1e9;
                if(j+1<m)
                    right += dp[i-1][j+1];
                else
                    right = 1e9;
                dp[i][j] = min(up,min(left,right));
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};