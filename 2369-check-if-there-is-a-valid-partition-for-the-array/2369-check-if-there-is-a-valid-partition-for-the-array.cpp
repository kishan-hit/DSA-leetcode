class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1);
        dp[n] = 1;
        for(int i=n-2;i>=0;i--){
            int p1=0,p2=0,p3=0;
            if(i==n-2){
                if(i+1<n && nums[i]==nums[i+1])
                p1 = dp[i+2];
            }
            else{
                if(i+1<n && nums[i]==nums[i+1])
                    p1 = dp[i+2];
                if(i+2<n && (nums[i]==nums[i+1])&&(nums[i+1]==nums[i+2]))
                    p2 = dp[i+3];
                if(i+2<n && ((nums[i]-nums[i+1])==-1)&&((nums[i+1]-nums[i+2])==-1))
                    p3 = dp[i+3];
            }
            dp[i] = p1||p2||p3;
        }
        return dp[0];
    }
};