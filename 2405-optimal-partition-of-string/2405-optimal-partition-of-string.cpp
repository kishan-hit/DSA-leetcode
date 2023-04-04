class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> mp;
        int j=0,cnt=1;
        while(j<s.length()){
            mp[s[j]]++;
            if(mp[s[j]]>1){
                ++cnt;
                mp.clear();
                mp[s[j]]++;
            }
            ++j;
        }
        return cnt;
    }
};