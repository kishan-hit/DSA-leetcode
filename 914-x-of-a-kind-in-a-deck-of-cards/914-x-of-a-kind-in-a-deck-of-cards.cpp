class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mp;
        int f=0;
        for(auto it:deck)
            mp[it]++;
        int res = 0;
        for(auto it:mp) 
            res = __gcd(it.second,res);
        return res>1;
    }
};