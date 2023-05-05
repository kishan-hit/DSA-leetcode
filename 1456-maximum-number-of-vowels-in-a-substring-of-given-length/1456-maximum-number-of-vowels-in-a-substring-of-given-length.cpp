class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<char,int> mp = {{'a',1},{'e',2},{'i',3},{'o',4},{'u',5}};
        int res=0,maxi=0;
        int i=0,j=0;
        while(j<s.length()){
            if(mp.find(s[j])!=mp.end())
                ++res;
            if((j-i+1)==k){
                maxi = max(maxi,res);
                if(mp.find(s[i])!=mp.end()){
                    --res;
                }
                ++i;
            }
            ++j;
        }
        return maxi;
    }
};