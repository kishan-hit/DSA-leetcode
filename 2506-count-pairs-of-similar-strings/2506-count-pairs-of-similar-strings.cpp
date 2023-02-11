class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n=words.size();
        vector<string>v;
        for(auto it:words){
            set<int>s;
            for(auto c:it){
                s.insert(c);
            }
            string t="";
            for(auto c:s){
                t+=c;
            }
            v.push_back(t);
        }
        int ans=0;
        unordered_map<string,int>mp;
        for(auto it:v){
            ans += mp[it];
            mp[it]++;
        }
      
        return ans;
    }
};