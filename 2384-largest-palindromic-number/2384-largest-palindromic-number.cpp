class Solution {
public:
    string largestPalindromic(string num) {
        int cnt=0;
        for(int i=0;i<num.length();i++)
            if(num[i]=='0')
                ++cnt;
        if(cnt==num.length())
            return "0";
        map<int,int> mp;
        for(auto it:num)
            mp[it-'0']++;
        int maxi=INT_MIN;
        int f=0;
        for(auto it:mp){
            if(it.second%2!=0){
                maxi = max(maxi,it.first);
                f=1;
            }
        }
        string res;
        for(auto it:mp){
            int temp = it.second/2;
            while(temp>0){
                res += (it.first+'0');
                --temp;
            }
        }
        string s = res;
        reverse(s.begin(),s.end());
        if(f)
            s += (maxi+'0');
        s += res;
        res = s;
        int i=0,f1=0;
        cnt=0;
        while(i<res.length() && res[i]=='0'){
            f1=1;
            ++i;
            ++cnt;
        }
        if(f1){
            s="";
            for(int j=cnt;j<res.length()-cnt;j++)
                s += res[j];
        }
        return s;
    }
};