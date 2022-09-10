class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> cur(2,vector<int> (k+1)),next(2,vector<int> (k+1));
        int profit = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int l=1;l<=k;l++){
                    if(j)
                        profit = max(next[1][l],-prices[i] + next[0][l]);
                    else
                        profit = max(next[0][l],prices[i] + next[1][l-1]);
                    cur[j][l] = profit;
                }
            }
            next = cur;
        }
        return next[1][k];
    }
};