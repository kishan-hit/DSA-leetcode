class Solution {
    public:
int solve(int i,int left,vector<int>& arr1,vector<int>& arr2,map<int, map<int,int>>& dp) {
        if(i==arr1.size()) 
            return 0;
        if(dp[i].find(left) != dp[i].end()) 
            return dp[i][left];
        int exclude = 1e8;
        if(arr1[i] > left) {
            exclude = solve(i+1, arr1[i], arr1, arr2, dp);
        }
        int include = 1e8;
        int j = upper_bound(arr2.begin(), arr2.end(), left) - arr2.begin();
        if(j < arr2.size()) {
            include = 1 + solve(i+1, arr2[j], arr1, arr2, dp);
        }
        return dp[i][left] = min(exclude, include);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        map<int, map<int, int>> dp;
        int ans = solve(0,INT_MIN,arr1,arr2,dp);
        return ans >= 1e8 ? -1 : ans;
    }
};