class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        map<char,int>  m={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        for(int i=0;i<s.length()-1;i++){
            if(m[s[i]]<m[s[i+1]])
                res -= m[s[i]];
            else
                res += m[s[i]];
        }
        res += m[s[s.length()-1]];
        return res;
    }
};