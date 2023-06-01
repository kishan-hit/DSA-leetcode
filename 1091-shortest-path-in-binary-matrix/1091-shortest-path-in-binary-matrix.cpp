class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0)
            return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        vector<vector<int>> dir = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int a = it.first;
            int b = it.second;
            if(a==n-1 && b==m-1)
                return grid[a][b];
            for(auto it1:dir){
                int x = a + it1[0];
                int y = b + it1[1];
                if(x>=0 && x<=n-1 && y>=0 && y<=m-1 && grid[x][y]==0){
                    q.push({x,y});
                    grid[x][y] = 1 + grid[a][b];
                }
            }  
        }
        return -1;
    }
};