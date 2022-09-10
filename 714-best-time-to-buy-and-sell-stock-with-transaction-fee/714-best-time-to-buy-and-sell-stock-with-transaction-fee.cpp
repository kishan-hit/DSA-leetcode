class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> cur(2),next(2);
        int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j)
                    profit = max(next[1],-prices[i] + next[0]);
                else
                    profit = max(next[0],(prices[i]-fee) + next[1]);
                cur[j] = profit;    
            }
            next = cur;
        }
        return next[1];
    }
};