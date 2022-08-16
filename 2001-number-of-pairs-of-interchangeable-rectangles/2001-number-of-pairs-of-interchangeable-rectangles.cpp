class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long res=0;
        map<pair<int,int>,int> mp;
        for(auto it:rectangles){
            int gcd = __gcd(it[0],it[1]);
            pair<int,int> p = {it[0]/gcd,it[1]/gcd};
            if(mp.find(p)!=mp.end())
                res += mp[p];
            mp[p]++;
        }
        return res;
    }
};