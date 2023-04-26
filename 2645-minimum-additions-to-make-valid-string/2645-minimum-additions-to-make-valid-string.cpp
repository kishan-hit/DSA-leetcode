class Solution {
public:
    int addMinimum(string word) {
        int res=0,cnt=1,i=0;
        for(i=0;i<word.length()-1;i++){
            if(word[i]<word[i+1])
                ++cnt;
            else{
                res += (3-cnt);
                cnt = 1;
            }
        }
        if(word[i]=='a')
            res += 2;
        else if(word[i]=='b'){
            if(!(i-1>=0 && word[i-1]=='a'))
                res += 2;
            else
                res += 1;
        }
        else{
            if(!(i-2>=0 && word[i-2]=='a' && word[i-1]=='b')){
                if(!(i-1>=0 && word[i-1]=='b') && (!(i-1>=0 && word[i-1]=='a')))
                    res += 2;
                else
                    res += 1;
            }
        }
        return res;
    }
};