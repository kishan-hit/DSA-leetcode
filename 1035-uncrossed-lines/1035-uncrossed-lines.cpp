class Solution {
public:
    int solve(vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp,int nums1Start,int nums2Start){
        if(nums1Start==nums1.size() || nums2Start==nums2.size()) 
            return 0;
        if (dp[nums1Start][nums2Start]!=-1) 
            return dp[nums1Start][nums2Start];
        int makeLineCount=0,notMakeLineCount=0;
        if(nums1[nums1Start]==nums2[nums2Start]) 
            makeLineCount = 1 + solve(nums1,nums2,dp,nums1Start+1,nums2Start+1);
        else{
            int leaveFromNums1 = solve(nums1,nums2,dp,nums1Start+1,nums2Start);
            int leaveFromNums2 = solve(nums1,nums2,dp,nums1Start,nums2Start+1);
            notMakeLineCount = max(leaveFromNums1, leaveFromNums2);
        }
        return dp[nums1Start][nums2Start] = max(makeLineCount, notMakeLineCount); 
    }
    int maxUncrossedLines(vector<int>& nums1,vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        int ans = solve(nums1,nums2,dp,0,0);
        return ans;
    }
};