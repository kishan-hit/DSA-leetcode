class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum=0;
        for(int i=0;i<nums.size();i++)
            sum += nums[i];
        if(x>sum)
            return -1;
        long long target = sum - x;
        int i=0,j=0,maxi=0,f=0;
        while(j<nums.size()){
            target -= nums[j];
            if(target==0){
                f=1;
                maxi = max(maxi,(j-i+1));
                target += nums[i];
                ++i;
            }
            while(target<0){
                target += nums[i];
                ++i;
                if(target==0){
                    f=1;
                    maxi = max(maxi,(j-i+1));
                }
            }
            ++j;
        }
        if(f==0)
            return -1;
        return nums.size()-maxi;
    }
};