class Solution {
public:
    string countAndSay(int n) {
        string s;
        for(int i=0;i<n;i++){
            if(i==0)
                s = "1";
            else{
                int cnt=0;
                string temp;
                for(int j=0;j<s.length();j++){
                    ++cnt;
                    if(j==s.length()-1 || s[j]!=s[j+1]){
                        temp += to_string(cnt) + s[j];
                        cnt = 0;
                    }
                }
                s = temp;
            }
        }
        return s;
    }
};