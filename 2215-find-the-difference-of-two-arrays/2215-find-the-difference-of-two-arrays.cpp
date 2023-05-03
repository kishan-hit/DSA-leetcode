class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> vec;
        vector<int> v;
        unordered_map<int,int> mp;
        for(auto it:nums2)
            mp[it]++;
        for(auto it:nums1)
            if(mp.find(it)==mp.end()){
                v.push_back(it);
                mp[it]++;
            }
        vec.push_back(v);
        mp.clear();
        v.clear();
        for(auto it:nums1)
            mp[it]++;
        for(auto it:nums2)
            if(mp.find(it)==mp.end()){
                v.push_back(it);
                mp[it]++;
            }
        vec.push_back(v);
        return vec;
    }
};