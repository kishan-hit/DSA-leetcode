class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size(),maxi=0;
        vector<long long> conversion(n);
        vector<long long> res(n);
        long long temp=0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            conversion[i] = (nums[i] + maxi);
            if(i>=1)
                temp += conversion[i-1];
            res[i] = temp + conversion[i];
        }
        return res;
    }
};