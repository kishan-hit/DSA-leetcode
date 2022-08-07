class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1));
        for(int j=0;j<=amount;j++)
            dp[0][j] = (j%coins[0]==0);
        for(int i=0;i<n;i++)
            dp[i][0] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int p=0;
                if(j>=coins[i])
                    p = dp[i][j-coins[i]];
                int np = dp[i-1][j];
                dp[i][j] = p+np;
            }
        }
        return dp[n-1][amount];
    }
};