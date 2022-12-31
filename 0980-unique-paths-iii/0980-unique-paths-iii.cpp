class Solution {
public:
    int dfs(vector<vector<int>>& grid,int sx,int sy,int cnt){
        if(sx<0 || sx>=grid.size() || sy<0 || sy>=grid[0].size() || grid[sx][sy]==-1)
            return 0;
        if(grid[sx][sy]==2)
            return cnt==-1;
        grid[sx][sy] = -1;
        int res = dfs(grid,sx+1,sy,cnt-1)+dfs(grid,sx-1,sy,cnt-1)+dfs(grid,sx,sy+1,cnt-1)+dfs(grid,sx,sy-1,cnt-1);
        grid[sx][sy] = 0;
        return res;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int cnt=0,sx=-1,sy=-1;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)
                    ++cnt;
                else if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
            }
        }
        return dfs(grid,sx,sy,cnt);
    }
};