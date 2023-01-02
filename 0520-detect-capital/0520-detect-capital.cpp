class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0;
        for(auto it:word){
            if(isupper(it))
                ++cnt;
        }
        if(cnt==0 || cnt==word.length() || (cnt==1 && isupper(word[0])))
            return true;
        return false;
    }
};