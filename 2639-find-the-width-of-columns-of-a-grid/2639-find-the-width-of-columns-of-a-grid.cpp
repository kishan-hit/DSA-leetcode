class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> v;
        for(int j=0;j<grid[0].size();j++){
            int maxi=0;
            for(int i=0;i<grid.size();i++){
                string str = to_string(grid[i][j]);
                if(str.length()>maxi)
                    maxi = str.length();
            }
            v.push_back(maxi);
        }
        return v;
    }
};