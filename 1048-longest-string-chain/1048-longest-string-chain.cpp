class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int maxi=1;
        unordered_map<string,int> mp;
        sort(words.begin(),words.end(),[](const string &a,const string &b){
            return a.length()<b.length();
        });
        for(auto it:words){
            mp[it] = 1;
            for(int i=0;i<it.length();i++){
                string prev = it.substr(0,i) + it.substr(i+1);
                if(mp.find(prev)!=mp.end()){
                    mp[it] = mp[prev] + 1;
                    maxi = max(maxi,mp[it]);
                }
            }
        }
        return maxi;
    }
};