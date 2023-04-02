class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<vector<int>> vec;
        for(auto it:nums)
            mp[it]++;
        while(mp.size()>0){
            vector<int> v;
            for(auto it:mp)
                v.push_back(it.first);
            for(auto it:v){
                mp[it]--;
                if(mp[it]==0)
                    mp.erase(it);
            }
            vec.push_back(v);
        }
        return vec;
    }
};