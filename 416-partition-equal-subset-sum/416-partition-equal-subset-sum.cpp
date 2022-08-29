class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2!=0)
            return 0;
        int k=sum/2;
        vector<vector<bool>>dp(nums.size(),vector<bool>(k+1,false));
        for(int i=0;i<nums.size();i++)
            dp[i][0]=1;
        for(int j=0;j<=k;j++)
            dp[0][j] = (nums[0]==j) ? true : false;
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=k;j++){
                bool np=dp[i-1][j];
                bool p=0;
                if(j>=nums[i])
                    p=dp[i-1][j-nums[i]];
                dp[i][j]=p|np;
            }
        }
        return dp[nums.size()-1][k];
    }
};