class Solution {
public:
    int mod=1e9+7;
    int f(int s, int e, int k, vector<vector<int>>&dp,int temp){
        if(k==0){
            if(s==e)
                return 1;
            return 0;
        }
        if(dp[s+temp][k]!=-1)
            return dp[s+temp][k];
        int left = f(s-1,e,k-1,dp,temp);
        int right = f(s+1,e,k-1,dp,temp);
        return dp[s+temp][k]=(left+right)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
         int temp=abs(k-startPos);
        vector<vector<int>>dp(startPos+k+temp+1,vector<int>(k+1,-1));
        return f(startPos,endPos,k,dp,temp);
    }
};