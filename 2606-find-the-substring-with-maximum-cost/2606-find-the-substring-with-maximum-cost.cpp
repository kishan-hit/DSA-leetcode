class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char,int> mp;
        for(int i=0;i<chars.length();i++)
            mp[chars[i]] = vals[i];
        int ans=0,temp=0;
        for(auto it:s){
            if(mp.find(it)==mp.end())
                temp += (it-'a'+1);
            else{
                if(mp[it]>0)
                    temp += mp[it];
                else
                    temp = max(0,temp+mp[it]);
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};