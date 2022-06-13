class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n=s.length(),m=sub.length();
        unordered_map<char,unordered_set<char>> mp;
        for(int i=0;i<mappings.size();i++)
            mp[mappings[i][0]].insert(mappings[i][1]);
        for(int i=0;i<=(n-m);i++){
            int f=0;
            for(int j=0;j<m;j++){
                char c1=s[i+j],c2=sub[j];
                if(c2!=c1 && mp[c2].find(c1)==mp[c2].end()){
                    f=1;
                    break;
                }
            }
            if(f==0)
                return true;
        }
        return false;
    }
};