class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)
            return 0;
        vector<int> v(n+1,1);
        v[0] = v[1] = 0;
        for(int i=2;i*i<=n;i++)
            if(v[i])
                for(int j=i*i;j<=n;j+=i)
                    v[j] = 0;    
        int res=0;
        for(int i=2;i<n;i++)
            if(v[i])
                ++res;
        return res;
    }
};