class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long res=0;
        unordered_map<double,int> mp;
        for(auto it:rectangles){
            double temp = (double)it[1]/it[0];
            if(mp.find(temp)!=mp.end())
                res += mp[temp];
            mp[temp]++;
        }
        return res;
    }
};