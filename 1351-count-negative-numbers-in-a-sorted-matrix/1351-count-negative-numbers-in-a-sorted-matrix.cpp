class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=grid[0].size()-1;j>=0;j--){
                if(grid[i][j]<0)
                    cnt ++;
                else
                    break;
            }
        }
        return cnt;
    }
};