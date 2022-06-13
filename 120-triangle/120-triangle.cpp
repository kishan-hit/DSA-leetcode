class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> prev(n);
        for(int i=0;i<n;i++)
            prev[i] = triangle[n-1][i];
        for(int i=n-2;i>=0;i--){
            vector<int> cur(n);
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + prev[j];
                int right = triangle[i][j] + prev[j+1];
                cur[j] = min(down,right);
            }
            prev = cur;
        }
        return prev[0];
    }
};