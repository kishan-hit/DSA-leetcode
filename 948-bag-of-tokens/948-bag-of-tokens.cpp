class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int i=0,j=n-1,score=0,maxi=0;
        while(i<=j){
            if(tokens[i]<=power){
                ++score;
                maxi = max(maxi,score);
                power -= tokens[i];
                ++i;
            }
            else if(score>0){
                power += tokens[j];
                --j;
                score--;
                maxi = max(maxi,score);
            }
            else
                break;
        }
        return maxi;
    }
};