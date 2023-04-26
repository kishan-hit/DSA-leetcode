class Solution {
public:
    int addMinimum(string word) {
        unordered_map<char,int> mp;
        int i=0,res=0,maxi=0;
        for(i=0;i<word.length()-1;i++){
            if(word[i]<word[i+1])
                mp[word[i]]++;
            else{
                mp[word[i]]++;
                for(auto it:mp)
                    maxi = max(maxi,it.second);
                res += (abs(maxi-mp['a']));
                res += (abs(maxi-mp['b']));
                res += (abs(maxi-mp['c']));
                maxi=0;
                mp.clear();
            }
        }
        mp[word[i]]++;
        for(auto it:mp)
            maxi = max(maxi,it.second);
        res += (abs(maxi-mp['a']));
        res += (abs(maxi-mp['b']));
        res += (abs(maxi-mp['c']));
        return res;
    }
};