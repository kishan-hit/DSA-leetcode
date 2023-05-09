class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int top=0,bottom=matrix.size()-1,left=0,right=matrix[0].size()-1;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++)
                v.push_back(matrix[top][i]);
            ++top;
            if(top>bottom || left>right)
                break;
            for(int i=top;i<=bottom;i++)
                v.push_back(matrix[i][right]);
            --right;
            if(top>bottom || left>right)
                break;
            for(int i=right;i>=left;i--)
                v.push_back(matrix[bottom][i]);
            --bottom;
            if(top>bottom || left>right)
                break;
            for(int i=bottom;i>=top;i--)
                v.push_back(matrix[i][left]);
            ++left;
            if(top>bottom || left>right)
                break;
        }
        return v;
    }
};