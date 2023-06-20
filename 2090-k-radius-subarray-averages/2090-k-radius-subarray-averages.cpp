class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long sum=0;
        int n=nums.size(),temp=2*k+1;
        vector<int> res(n,-1);
        for(int i=0;i<n;i++){
            sum += nums[i];
            if((i-temp)>=0)
                sum -= nums[(i-temp)];
            if(i>=(temp-1))
                res[(i-k)] = sum/temp;
        }
        return res;
    }
};