class Solution {
public:
    bool valid(int rsize,int csize,int r,int c){
        if(r<0 || r>=rsize || c<0 || c>=csize)
            return false;
        return true;
    }
    int DFS(vector<vector<int>>& grid,int r,int c){
        if(r==grid.size())
            return c;
        if(valid(grid.size(),grid[0].size(),r,c)){
            if(grid[r][c]==1){
                if(valid(grid.size(),grid[0].size(),r,c+1)&&grid[r][c+1]==1){
                    return DFS(grid,r+1,c+1);
                }
            }
            else{
                if(valid(grid.size(),grid[0].size(),r,c-1)&&grid[r][c-1]==-1){
                    return DFS(grid,r+1,c-1);
                }
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid){
        int n = grid.size(),m = grid[0].size();
        vector<int>ans(m,0);
        for(int i=0;i<m;i++)
            ans[i] = DFS(grid,0,i);
        return ans;
    }
};