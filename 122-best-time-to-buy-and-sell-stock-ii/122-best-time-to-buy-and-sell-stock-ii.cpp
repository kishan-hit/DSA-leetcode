class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> next(2),cur(2);
        int profit = 0;
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j)
                    profit = max((-prices[i] + next[0]),next[1]);
                else
                    profit = max((prices[i] + next[1]),next[0]);
                cur[j] = profit;
            }
            next = cur;
        }
        return next[1];
    }
};