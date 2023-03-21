class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,maxi=0,res=0;
        int n = s.length();
        unordered_map<char,int> mp;
        while(j<n){
            mp[s[j]]++;
            maxi = max(maxi,mp[s[j]]);
            while((j-i+1)-maxi > k){
                mp[s[i]]--;
                ++i;
                maxi = max(maxi,mp[s[i]]);
            }
            res = max(res,(j-i+1));
            ++j;
        }
        return res;
    }
};