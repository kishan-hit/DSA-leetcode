class Solution {
public:
    int mod=1e9+7;
    int fun(int a,int b){
        if(b==0)
            return 1;
        if(b==1)
            return a;
        long long res;
        if(b%2==0){
            res = fun(a,b/2);
            res = (res%mod*res%mod)%mod;
        }
        else{
            res = fun(a,b-1);
            res = (res%mod*a)%mod;
        }
        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int res=0;
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                res = (res%mod + fun(2,j-i)%mod)%mod;
                ++i;
            }
            else
                --j;
        }
        return res;
    }
};