class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.length();
        if(n>haystack.length())
            return -1;
        for(int i=0;i<=haystack.length()-n;i++){
            string str = haystack.substr(i,n);
            if(str==needle)
                return i;
        }
        return -1;
    }
};