class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> vec(n,vector<int>(m,-1));
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vec[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(int i=0;i<dir.size();i++){
                int a = it.first + dir[i][0];
                int b = it.second + dir[i][1];
                if((a>=0 && a<n && b>=0 && b<m) && vec[a][b]==-1){
                    q.push({a,b});
                    vec[a][b] = vec[it.first][it.second] + 1;
                }
            }
        }
        return vec;
    }
};