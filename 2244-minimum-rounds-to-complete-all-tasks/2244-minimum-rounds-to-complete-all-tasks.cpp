class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int cnt=0;
        unordered_map<int,int> mp;
        for(auto it:tasks)
            mp[it]++;
        for(auto it:mp){
            if(it.second==1)
                return -1;
            while(it.second>=3){
                it.second -= 3;
                ++cnt;
                if(it.second==1){
                    ++cnt;
                    break;
                }
            }
            while(it.second>=2){
                it.second -= 2;
                ++cnt;
            }
        }
        return cnt;
    }
};