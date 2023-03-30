class Solution {
public:
    unordered_map<string,bool> mp;
    bool fun(string s1,string s2){
        int n = s1.length();
        if(s1==s2)
            return true;
        if(n<=1)
            return false;
        string s = s1 + s2;
        if(mp.find(s)!=mp.end())
            return mp[s];
        for(int i=1;i<=n-1;i++){
            if((fun(s1.substr(0,i),s2.substr(0,i)) && fun(s1.substr(i),s2.substr(i))) ||
               (fun(s1.substr(0,i),s2.substr(n-i)) && fun(s1.substr(i),s2.substr(0,n-i))))
                return mp[s] = true;
        }
        return mp[s] = false;
    }
    bool isScramble(string s1, string s2) {
        return fun(s1,s2);
    }
};