class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt=0,cnt1=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5)
                ++cnt;
            else if(bills[i]==10){
                --cnt;
                ++cnt1;
            }
            else{
                if(cnt1>=1){
                    --cnt1;
                    --cnt;
                }
                else
                    cnt -= 3;
            }
            if(cnt<0)
                return false;
        }
        return true;
    }
};