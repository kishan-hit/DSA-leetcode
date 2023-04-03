class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> mp;
        vector<bool> vis(256,false);
        for(auto it:s)
            mp[it]++;
        string res;
        res += s[0];
        vis[s[0]] = true;
        mp[s[0]]--;
        if(mp[s[0]]==0)
            mp.erase(s[0]);
        for(int i=1;i<s.length();i++){
            mp[s[i]]--;
            if(mp[s[i]]==0)
                mp.erase(s[i]);
            if(vis[s[i]])
                continue;
            while(!res.length()==0 && s[i]<res.back() && mp.find(res.back())!=mp.end()){
                vis[res.back()] = false;
                res.pop_back();
            }
            res += s[i];
            vis[s[i]] = true;
        }
        return res;
    }
};