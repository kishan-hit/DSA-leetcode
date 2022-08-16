class Solution {
public:
    int nthUglyNumber(int n, int A, int B, int C) {
        long long a = A;
        long long b = B;
        long long c = C;
        long long l = 1,h = (int)2*1e9;
        long long ab = (a*b)/__gcd(a,b);
        long long bc = (b*c)/__gcd(b,c);
        long long ac = (a*c)/__gcd(a,c);
        long long abc = (a*bc)/__gcd(a,bc);
        while(l<h){
            long long mid = l + (h-l)/2;
            long long cnt = (mid/a + mid/b + mid/c + mid/abc - mid/ab - mid/bc - mid/ac);
            if(cnt<n)
                l = mid + 1;
            else
                h = mid;
        }
        return (int)l;
    }
};