class Solution {
public:
    int addMinimum(string word) {
        unordered_map<char,int> mp;
        int i=0,res=0;
        for(i=0;i<word.length()-1;i++){
            if(word[i]<word[i+1])
                mp[word[i]]++;
            else{
                mp[word[i]]++;
                res += (3-(mp['a']+mp['b']+mp['c']));
                mp.clear();
            }
        }
        mp[word[i]]++;
        res += (3 - (mp['a']+mp['b']+mp['c']));
        return res;
    }
};