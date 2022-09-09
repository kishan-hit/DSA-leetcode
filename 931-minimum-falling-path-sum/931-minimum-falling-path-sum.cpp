class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> prev(m),cur(m);
        for(int j=0;j<m;j++)
            cur[j] = prev[j] = matrix[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up = matrix[i][j],left = matrix[i][j],right = matrix[i][j];
                up += prev[j];
                if(j-1>=0)
                    left += prev[j-1];
                else
                    left = 1e9;
                if(j+1<m)
                    right += prev[j+1];
                else
                    right = 1e9;
                cur[j] = min(up,min(left,right));
            }
            prev = cur;
        }
        return *min_element(prev.begin(),prev.end());
    }
};