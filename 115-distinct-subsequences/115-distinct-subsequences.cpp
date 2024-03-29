class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<double> prev(m+1),cur(m+1);
        for(int i=1;i<=n;i++){
            prev[0] = 1;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    cur[j] = prev[j-1] + prev[j];
                else
                    cur[j] = prev[j];
            }
            prev = cur;
        }
        return (int)prev[m];
    }
};