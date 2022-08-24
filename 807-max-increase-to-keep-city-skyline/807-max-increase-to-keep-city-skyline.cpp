class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> v1(grid.size()),v2(grid[0].size());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                v1[i] = max(v1[i],grid[i][j]);
                v2[j] = max(v2[j],grid[i][j]);
            }
        }
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++)
                res += min(v1[i],v2[j]) - grid[i][j];
        }  
        return res;
    }
};