class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 && n==1)
            return n;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i=0;i<trust.size();i++){
            mp1[trust[i][0]]++;
            mp2[trust[i][1]]++;
        }
        int sz = mp1.size();
        for(auto it:mp2){
            if(sz==n-1 && it.second==sz && mp1.find(it.first)==mp1.end())
                return it.first;
        }
        return -1;
    }
};