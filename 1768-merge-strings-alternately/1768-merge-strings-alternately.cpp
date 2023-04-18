class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        int i=0,mini=min(n1,n2);
        string res;
        while(i<mini){
            res += word1[i];
            res += word2[i];
            ++i;
        }
        if(i<n1)
            res += word1.substr(i,n1-i+1);
        if(i<n2)
            res += word2.substr(i,n2-i+1);
        return res;
    }
};