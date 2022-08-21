class Solution {
public:
    int minNumberOfHours(int inEn, int inExp, vector<int>& en, vector<int>& exp) {
        int n=en.size();
        int res=0;
        for(int i=0;i<n;i++){
            if(inEn>en[i]){
                inEn -= en[i];
            }
            else{
                int dif = abs(inEn-en[i]) + 1;
                res += dif;
                inEn += dif;
                inEn -= en[i];
            }
            if(inExp>exp[i]){
                inExp += exp[i];
            }
            else{
                int dif = abs(inExp-exp[i]) + 1;
                res += dif;
                inExp += dif + exp[i];
            }
        }
        return res;
    }
};