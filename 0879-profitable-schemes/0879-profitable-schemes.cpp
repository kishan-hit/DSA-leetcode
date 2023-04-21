class Solution {
public:
    int mod = 1e9+7;
    vector<vector<vector<int>>> dp;
    int fun(int n,int minProfit,vector<int>&group,vector<int>&profit,int i,int sum){
        if(n<0)
            return 0;
        if(i==group.size()){
            if(minProfit<=0)
                return 1;
            return 0;
        }
        if(dp[n][minProfit+sum][i]!=-1)
            return dp[n][minProfit+sum][i];
        int np = fun(n,minProfit,group,profit,i+1,sum);
        int p = fun(n-group[i],minProfit-profit[i],group,profit,i+1,sum);
        return dp[n][minProfit+sum][i] = (p+np)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        long long sum = 0;
        for(auto it:profit)
            sum += it;
        dp = vector<vector<vector<int>>> (n+1,vector<vector<int>> (minProfit+sum+1,vector<int> (m,-1)));
        return fun(n,minProfit,group,profit,0,sum);
    }
};