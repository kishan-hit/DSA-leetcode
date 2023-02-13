//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int row,int col,vector<int>&del_row,vector<int>&del_col,vector<vector<int>>&vis,
    vector<vector<char>>&mat){
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int temp_r = row + del_row[i];
            int temp_c = col + del_col[i];
            if(temp_r>=0 && temp_r<mat.size() && temp_c>=0 && temp_c<mat[0].size() && !vis[temp_r][temp_c]
            && mat[temp_r][temp_c]=='O')
                dfs(temp_r,temp_c,del_row,del_col,vis,mat);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here  
        vector<vector<int>> vis(n,vector<int>(m));
        vector<int> del_row = {-1,0,1,0};
        vector<int> del_col = {0,1,0,-1};
        for(int j=0;j<m;j++){
            if(mat[0][j]=='O' && !vis[0][j])
                dfs(0,j,del_row,del_col,vis,mat);
            if(mat[n-1][j]=='O' && !vis[n-1][j])
                dfs(n-1,j,del_row,del_col,vis,mat);
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && !vis[i][0])
                dfs(i,0,del_row,del_col,vis,mat);
            if(mat[i][m-1]=='O' && !vis[i][m-1])
                dfs(i,m-1,del_row,del_col,vis,mat);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O')
                    mat[i][j] = 'X';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends