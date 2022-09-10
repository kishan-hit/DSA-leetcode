class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0],maxi=0,res=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>mini)
                res = (prices[i]-mini);
            mini = min(mini,prices[i]);
            maxi = max(maxi,res);
        }
        return maxi;
    }
};