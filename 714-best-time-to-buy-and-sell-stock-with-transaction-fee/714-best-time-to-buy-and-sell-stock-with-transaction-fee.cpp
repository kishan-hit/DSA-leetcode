class Solution {
public:
    int fun(int i,int buy,vector<int>&prices,int fee,vector<vector<int>>&dp){
        int profit = 0;
        if(i==prices.size())
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy)
            profit += max(fun(i+1,1,prices,fee,dp),-prices[i] + fun(i+1,0,prices,fee,dp));
        else
            profit += max(fun(i+1,0,prices,fee,dp),(prices[i]-fee) + fun(i+1,1,prices,fee,dp));
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return fun(0,1,prices,fee,dp);
    }
};