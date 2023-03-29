class Solution {
public:
    int fun(vector<int>&nums,int ind,vector<int>&dp){
        int res=1e9;
        if(ind>=nums.size()-1)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        for(int j=1;j<=nums[ind];j++){
            if(ind+j>nums.size())
                break;
            res = min(res,1 + fun(nums,ind+j,dp));
        }
        return dp[ind] = res;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return fun(nums,0,dp);
    }
};