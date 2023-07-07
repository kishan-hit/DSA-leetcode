class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0,j=0,res=0,t=0,f=0,n=answerKey.length();
        while(j<n){
            answerKey[j] == 'T' ? t++ : f++;
            int temp = min(t,f);
            if(temp<=k)
                res = max(res,(j-i+1));
            while(temp>k){
                answerKey[i] == 'T' ? t-- : f--;
                temp = min(t,f);
                ++i;
            }
            ++j;
        }
        return res;
    }
};