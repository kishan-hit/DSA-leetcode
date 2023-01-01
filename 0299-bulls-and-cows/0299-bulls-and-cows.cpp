class Solution {
public:
    string getHint(string secret, string guess) {
        int cnt1=0,cnt2=0;
        vector<int> v1(10),v2(10);
        for(int i=0;i<secret.length();i++){
            char a = secret[i];
            char b = guess[i];
            if(a==b)
                ++cnt1;
            else{
                ++v1[a-'0'];
                ++v2[b-'0'];
            }
        }
        for(int i=0;i<v1.size();i++){
            cnt2 += min(v1[i],v2[i]);
        }
        return to_string(cnt1) + 'A' + to_string(cnt2) + 'B';
    }
};