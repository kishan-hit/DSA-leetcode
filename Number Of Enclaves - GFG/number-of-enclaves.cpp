//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row,int col,vector<int>&del_r,vector<int>&del_c,vector<vector<int>>&vis,
    vector<vector<int>>&grid){
        vis[row][col] = 1;
        grid[row][col] = 0;
        for(int i=0;i<4;i++){
            int temp_r = row + del_r[i];
            int temp_c = col + del_c[i];
            if(temp_r>=0 && temp_r<grid.size() && temp_c>=0 && temp_c<grid[0].size() && !vis[temp_r][temp_c]
            && grid[temp_r][temp_c]==1)
                dfs(temp_r,temp_c,del_r,del_c,vis,grid);
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size()));
        vector<int> del_r = {-1,0,1,0};
        vector<int> del_c = {0,1,0,-1};
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==1 && !vis[i][0])
                dfs(i,0,del_r,del_c,vis,grid);
            if(grid[i][grid[0].size()-1]==1 && !vis[i][grid[0].size()-1])
                dfs(i,grid[0].size()-1,del_r,del_c,vis,grid);
        }
        for(int j=0;j<grid[0].size();j++){
            if(grid[0][j]==1 && !vis[0][j])
                dfs(0,j,del_r,del_c,vis,grid);
            if(grid[grid.size()-1][j]==1 && !vis[grid.size()-1][j])
                dfs(grid.size()-1,j,del_r,del_c,vis,grid);
        }
        int cnt=0;
        for(int i=1;i<grid.size()-1;i++){
            for(int j=1;j<grid[0].size()-1;j++)
                if(grid[i][j])
                    ++cnt;
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends