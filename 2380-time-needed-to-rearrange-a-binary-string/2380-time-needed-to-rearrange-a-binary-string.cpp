class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n=s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            int f=0;
            for(int j=0;j<n-1;j++){
                if(s[j]=='0' && s[j+1]=='1'){
                    swap(s[j],s[j+1]);
                    f=1;
                    ++j;
                }
            }
            if(f)
                ++cnt;
        }
        return cnt;
    }
};