class Solution {
public:
    int fun(vector<int>&nums,int i,int n,vector<int>&dp){
        if(i>=n)
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        int p1=0,p2=0,p3=0;
        if(i+1<n && nums[i]==nums[i+1])
            p1 = fun(nums,i+2,n,dp);
        if(i+2<n && (nums[i]==nums[i+1])&&(nums[i+1]==nums[i+2]))
            p2 = fun(nums,i+3,n,dp);
        if(i+2<n && ((nums[i]-nums[i+1])==-1)&&((nums[i+1]-nums[i+2])==-1))
            p2 = fun(nums,i+3,n,dp);
        return dp[i] = p1||p2||p3;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return fun(nums,0,n,dp);
    }
};