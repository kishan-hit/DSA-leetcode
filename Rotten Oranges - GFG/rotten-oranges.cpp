//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(grid.size(),vector<int> (grid[0].size()));
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else if(grid[i][j]==1)
                    ++fresh;
            }
        }
        int cnt=0,fresh_cnt=0;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int temp = q.front().second;
            q.pop();
            cnt = max(cnt,temp);
            vector<int> del_i = {-1,0,1,0};
            vector<int> del_j = {0,-1,0,1};
            for(int k=0;k<4;k++){
                int temp_i = i + del_i[k];
                int temp_j = j + del_j[k];
                if(temp_i>=0 && temp_i<grid.size() && temp_j>=0 && temp_j<grid[0].size()
                && grid[temp_i][temp_j]==1 && !vis[temp_i][temp_j]){
                    q.push({{temp_i,temp_j},temp+1});
                    ++fresh_cnt;
                    grid[temp_i][temp_j] = 2;
                    vis[temp_i][temp_j] = 1;
                }
            }
        }
        if(fresh!=fresh_cnt)
            return -1;
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends