class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        for(auto it:nums)
            if(it==1)
                ++cnt;
        if(cnt)
            return (n-cnt);
        int res = INT_MAX;
        for(int i=0;i<n-1;i++){
            int temp = nums[i];
            for(int j=i+1;j<n;j++){
                temp = __gcd(temp,nums[j]);
                if(temp==1){
                    res = min(res,(j-i+(n-1)));
                    break;
                }
            }
        }
        return res==INT_MAX?-1:res;
    }
};