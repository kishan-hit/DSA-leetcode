class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        int maxi=INT_MIN;
        for(auto it:mp)
            maxi = max(maxi,it.second);
        int i=0,j=0;
        mp.clear();
        int mini=INT_MAX;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp[nums[j]]==maxi){
                while(nums[i]!=nums[j])
                    ++i;
                mini = min(mini,(j-i+1));
                i=0;
            }
            ++j;
        }
        return mini;
    }
};