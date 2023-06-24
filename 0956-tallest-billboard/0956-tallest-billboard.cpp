const int maxn = 5000;
class Solution {
public:
    int f[21][maxn + 1];
    int tallestBillboard(vector<int>& rods) {
        for (int i = 0; i <= maxn; i++)
            f[0][i] = -1e9;
        f[0][0] = 0;
        int n = rods.size();
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= maxn; j++) {
                f[i][j] = f[i-1][j];
                if (j >= rods[i-1])
                    f[i][j] = max(f[i][j], f[i-1][j-rods[i-1]]+rods[i-1]);
                if (j <  rods[i-1])
                    f[i][j] = max(f[i][j], f[i-1][rods[i-1]-j]+j);
                if (j+rods[i-1] <= maxn)
                    f[i][j] = max(f[i][j], f[i-1][j+rods[i-1]]);
            }
        return f[n][0];
    }
};