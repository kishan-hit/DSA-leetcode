class Solution {
public:
    int fun(int amount,vector<int>&coins,int i,vector<vector<int>>&dp){
        if(i==0)
            return (amount%coins[0]==0);
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        if(amount==0)
            return 1;
        int p=0;
        if(amount>=coins[i])
            p = fun(amount-coins[i],coins,i,dp);
        int np = fun(amount,coins,i-1,dp);
        return dp[i][amount] = p + np;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return fun(amount,coins,n-1,dp);
    }
};