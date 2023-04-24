class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        map<int,int> mp;
        vector<int> v;
        int j=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if((i-j+1)==k){
                int sum=0,res;
                for(auto it:mp){
                    sum += it.second;
                    if(sum>=x){
                        res = it.first;
                        if(res<0)
                            v.push_back(res);
                        else
                            v.push_back(0);
                        break;
                    }
                }
                mp[nums[j]]--;
                if(mp[nums[j]]==0)
                    mp.erase(nums[j]);
                ++j;
            }
        }
        return v;
    }
};