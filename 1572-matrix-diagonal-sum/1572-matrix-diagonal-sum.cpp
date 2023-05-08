class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int sum=0,i=0,j=m-1,k=0;
        while(k<n){
            if(i==j)
                sum += mat[i][j];
            else
                sum += (mat[i][k] + mat[k][j]);
            ++i;
            --j;
            ++k;
        }
        return sum;
    }
};