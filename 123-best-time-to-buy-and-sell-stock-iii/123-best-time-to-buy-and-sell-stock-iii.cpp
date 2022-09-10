class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> cur(2,vector<int>(3)),next(2,vector<int>(3));
        int profit=0;
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=2;k++){
                    if(j)
                        profit = max(next[1][k],-prices[i] + next[0][k]);
                    else
                        profit = max(next[0][k],prices[i] + next[1][k-1]);
                    cur[j][k] = profit;
                }
            }
            next = cur;
        }
        return next[1][2];
    }
};