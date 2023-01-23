class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 && n==1)
            return n;
        unordered_map<int,int> mp;
        for(int i=0;i<trust.size();i++){
            --mp[trust[i][0]];
            ++mp[trust[i][1]];
        }
        for(auto it:mp){
            if(it.second==n-1)
                return it.first;
        }
        return -1;
    }
};