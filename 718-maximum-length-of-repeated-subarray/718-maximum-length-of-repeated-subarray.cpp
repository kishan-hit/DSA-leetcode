class Solution {
public:
    int fun(vector<int>&nums1,vector<int>&nums2,int i,int j,int &maxi,vector<vector<int>>&dp){
        if(i==0 || j==0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int cur=0;
        if(nums1[i-1]==nums2[j-1])
            cur = 1 + fun(nums1,nums2,i-1,j-1,maxi,dp);
        fun(nums1,nums2,i-1,j,maxi,dp);
        fun(nums1,nums2,i,j-1,maxi,dp);
        maxi = max(maxi,cur);
        return dp[i][j] = cur;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int maxi=0;
        fun(nums1,nums2,n,m,maxi,dp);
        return maxi;
    }
};