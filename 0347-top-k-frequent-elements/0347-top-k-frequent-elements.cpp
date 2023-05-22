class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        vector<pair<int,int>> vec;
        unordered_map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        for(auto it:mp)
            vec.push_back({it.second,it.first});
        sort(vec.rbegin(),vec.rend());
        // reverse(vec.begin(),vec.end());
        int i=0;
        while(i<k){
            v.push_back(vec[i].second);
            ++i;
        }
        return v;
    }
};