class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int cnt=0;
        int n = grid.size();
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            vector<int> u(n);
            for(int j=0;j<n;j++)
                u[j] = grid[j][i];
            v[i] = u;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i] == v[j])
                    ++cnt;
            }
        }
        return cnt;
    }
};