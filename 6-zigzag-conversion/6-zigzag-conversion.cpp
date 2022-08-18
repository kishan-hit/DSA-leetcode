class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        int n=s.length();
        vector<string> v(numRows,"");
        int i=0,temp;
        for(int j=0;j<n;j++){
            v[i] += s[j];
            if(i==0)
                temp = 1;
            else if(i==numRows-1)
                temp = -1;
            i += temp;
        }
        string st;
        for(auto it:v)
            st += it;
        return st;
    }
};