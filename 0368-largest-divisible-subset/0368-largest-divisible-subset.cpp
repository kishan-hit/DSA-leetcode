class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1),v(n);
        int maxi = 1;
        int ind = 0;
        for(int i=0;i<n;i++){
            v[i] = i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && (dp[j] + 1)> dp[i]){
                    dp[i] = 1 + dp[j];
                    v[i] = j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                ind = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[ind]);
        while(v[ind]!=ind){
            ind = v[ind];
            temp.push_back(nums[ind]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};