class Solution {
public:
    int lengthOfLongestSubstring(string S) {
        int i=0,j=0,n=S.length();
        unordered_map<char,int> mp;
        int maxi=0;
        while(j<n){
            mp[S[j]]++;
            while(mp[S[j]]>1){
                mp[S[i]]--;
                // if(mp[S[i]]==0)
                //     mp.erase(S[i]);
                ++i;
            }
            maxi = max(maxi,(j-i+1));
            ++j;
        }
        return maxi;
    }
};