class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        for(auto it:nums){
            if(mp[it]>0){
                int f = mp[it],cnt=0,cur=it;
                while(mp.find(cur)!=mp.end() && mp[cur]>=f){
                    ++cnt;
                    f = max(f,mp[cur]);
                    mp[cur]--;
                    ++cur;
                }
                if(cnt<3)
                    return false;
            }
        }
        return true;
    }
};