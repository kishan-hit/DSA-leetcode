class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> v;
        unordered_map<int,int> mp;
        for(auto it:arr)
            mp[it]++;
        int i=1;
        while(v.size()<k){
            if(mp.find(i)==mp.end())
                v.push_back(i);
            ++i;
        }
        return v[v.size()-1];
    }
};