class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        vector<long long> v(nums.size());
        long long maxi=INT_MIN;
        v[0] = nums[0];
        for(int i=1;i<nums.size();i++)
            v[i] = v[i-1] + nums[i];
        long long res;
        for(int i=0;i<v.size();i++){
            res = ceil(v[i]*(1.0)/(i+1));
            maxi = max(maxi,res);
        }
        return (int)maxi;
    }
};