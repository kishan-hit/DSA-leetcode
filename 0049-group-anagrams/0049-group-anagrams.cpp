class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vec;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);
        }
        for(auto it:mp){
            vector<string> v = it.second;
            vec.push_back(v);
        }
        return vec;
    }
};