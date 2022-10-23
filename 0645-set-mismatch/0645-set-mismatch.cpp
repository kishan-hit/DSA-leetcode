class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        for(auto it:nums)
            sum += it;
        int temp = 0,cnt=1;
        for(int i=0;i<nums.size();i++){
            temp += cnt;
            ++cnt;
        }
        int diff = (temp-sum);
        for(int i=1;i<nums.size();i++)
            if(nums[i]==nums[i-1])
                    return {nums[i],(nums[i]+diff)};
        return {};
    }
};