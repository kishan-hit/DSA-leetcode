class Solution {
public:
    int fun(vector<vector<int>>&piles,int i,int k,vector<vector<int>>&dp){
        if(i==piles.size())
            return 0;
        int maxi=0;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int np = fun(piles,i+1,k,dp);
        int p=0;
        int n = piles[i].size();
        int mini = min(k,n);
        for(int j=0;j<mini;j++){
            p += piles[i][j];
            maxi = max(maxi,max(p+fun(piles,i+1,k-(j+1),dp),np));
        }
        return dp[i][k] = maxi;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        return fun(piles,0,k,dp);
    }
};