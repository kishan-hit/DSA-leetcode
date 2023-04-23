class Solution {
public:
    long long mod=1e9+7;
    vector<long long> dp;
    int fun(string &s,int k,int i){
        if(i==s.length())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        long long res = 0;
        long long temp = 0;
        for(int j=i;j<s.length();j++){
            temp = temp*10 + (s[j]-'0');
            if(temp<=k && temp>=1ll)
                res = (res + fun(s,k,j+1))%mod;
            else
                break;
        }
        return dp[i] = res;
    }
    int numberOfArrays(string s, int k) {
        int n = s.length();
        dp = vector<long long> (n+1,-1);
        return fun(s,k,0);
    }
};