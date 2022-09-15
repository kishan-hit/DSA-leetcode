class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        vector<int> v;
        map<int,int> mp;
        for(auto it:c)
            mp[it]++;
        // if(mp.find(0)!=mp.end() && mp[0]&1)
        //     return {};
        // if(mp.find(0)!=mp.end())
        //     for(int i=0;i<mp[0]/2;i++)
        //         v.push_back(0);
        // mp.erase(0);
        while(mp.size()){
            auto it = mp.begin();
            if((it->first==0 && mp[it->first]&1) || mp.find(2*(it->first))==mp.end())
                return {};
            v.push_back(it->first);
            mp[2*(it->first)]--;
            if(mp[2*(it->first)]==0)
                mp.erase(2*(it->first));
            mp[it->first]--;
            if(mp[it->first]==0)
                mp.erase(it->first);
        }
        return v;
    }
};