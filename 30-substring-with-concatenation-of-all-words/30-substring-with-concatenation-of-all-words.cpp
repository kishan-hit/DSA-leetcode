class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++)
            m[words[i]]++;
        int totlen=words[0].size()*words.size();
        for(int i=0;i+totlen<=s.size();i++){
            string curr=s.substr(i,totlen);
            unordered_map<string,int> n;
            int j=0;
            while(j+words[0].size()<=curr.size()){
                n[curr.substr(j,words[0].size())]++;
                j=j+words[0].size();
            }
            if(n==m)
                ans.push_back(i);
        }
        return ans;
    }
};