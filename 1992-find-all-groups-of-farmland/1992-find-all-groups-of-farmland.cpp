class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size(),m=land[0].size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    int k=i,l=j;
                    while(k<n && land[k][j]==1)
                        ++k;
                    while(l<m && land[i][l]==1)
                        ++l;
                    --k,--l;
                    v.push_back({i,j,k,l});
                    for(int m=i;m<=k;m++)
                        for(int n=j;n<=l;n++)
                            land[m][n] = -1;
                }
            }
        }
        return v;
    }
};