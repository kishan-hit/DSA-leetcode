class Solution {
public:
    int concatenatedBinary(int n) {
        long long res=0,len=0,mod=1e9+7;
        for(int i=1;i<=n;i++){
            len = 1 + log2(i);
            res = (res<<len)%mod;
            res = (res + i)%mod;
        }
        return (int)res;
    }
};