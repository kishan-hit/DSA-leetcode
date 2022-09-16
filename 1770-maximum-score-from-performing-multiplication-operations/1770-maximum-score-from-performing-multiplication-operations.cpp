class Solution {
public:
    int fun(vector<int>&nums,vector<int>&m,int i,int l,int r,vector<vector<int>>&dp){
        // if(i==m.size()-1)
        //     return max(m[i]*nums[l],m[i]*nums[r]);
        if(i==m.size())
            return 0;
        if(dp[i][l]!=INT_MIN)
            return dp[i][l];
        int left = m[i]*nums[l] + fun(nums,m,i+1,l+1,r,dp);
        int right = m[i]*nums[r] + fun(nums,m,i+1,l,r-1,dp);
        return dp[i][l] = max(left,right);
    }
    int maximumScore(vector<int>& nums, vector<int>& m) {
        vector<vector<int>> dp(m.size()+1,vector<int>(m.size()+1,INT_MIN));
        return fun(nums,m,0,0,nums.size()-1,dp);
    }
};