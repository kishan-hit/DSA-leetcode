class Solution {
public:
    int addDigits(int num) {
        string str = to_string(num);
        while(str.length()!=1){
            int res = 0;
            for(int i=0;i<str.length();i++)
                res += (str[i]-'0');
            str = to_string(res);
        }
        return stoi(str);
    }
};