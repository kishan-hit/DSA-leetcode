class Solution {
public:
    void dfs(vector<vector<int>>&heights,vector<vector<bool>>& visited,int i,int j) {
        int m = heights.size();
        int n = heights[0].size();
        visited[i][j] = true;
        if(i-1>=0 && !visited[i-1][j] && heights[i-1][j]>=heights[i][j])
            dfs(heights,visited,i-1,j);
        if(i+1<m && !visited[i+1][j] && heights[i+1][j]>=heights[i][j])
            dfs(heights,visited,i+1,j);
        if(j-1>=0 && !visited[i][j-1] && heights[i][j-1]>=heights[i][j])
            dfs(heights,visited,i,j-1);
        if(j+1<n && !visited[i][j+1] && heights[i][j+1]>=heights[i][j])
            dfs(heights,visited,i,j+1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> r;
        int m = heights.size();
        if(m==0)
            return r;
        int n = heights[0].size();
        if(n==0)
            return r;
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        for(int i=0;i<m;i++){
            dfs(heights,pacific,i,0);
            dfs(heights,atlantic,i,n-1);
        }
        for(int j=0;j<n;j++){
            dfs(heights,pacific,0,j);
            dfs(heights,atlantic,m-1,j);
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(pacific[i][j] && atlantic[i][j])
                    r.push_back({i,j});
        return r;
    }
};