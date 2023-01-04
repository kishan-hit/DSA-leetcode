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
            else if(it.second%3==0){
                cnt += it.second/3;
            }
            else{
                cnt += it.second/3 + 1;
            }
        }
        return cnt;
    }
};