class Solution {
public:
    int addMinimum(string word) {
        int res=0;
        for(int i=0;i<word.length();){
            int cnt=0;
            if(word[i]=='a'){
                ++cnt;
                ++i;
            }
            if(word[i]=='b'){
                ++cnt;
                ++i;
            }
            if(word[i]=='c'){
                ++cnt;
                ++i;
            }
            res += (3-cnt);
        }
        return res;
    }
};