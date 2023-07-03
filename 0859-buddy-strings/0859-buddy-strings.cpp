class Solution {
public:
    bool buddyStrings(string s, string goal) {
        string tmp1="",tmp2="",tmp3,tmp4;
        int k=0,n1=s.length(),n2=goal.length(),cnt=0;
        if(n1!=n2)
            return false;
        while(k<n1){
            if(s[k]!=goal[k]){
                ++cnt;
                if(cnt==1){
                    tmp1 += s[k];
                    tmp3 += goal[k];
                }
                else if(cnt==2){
                    tmp2 += goal[k];
                    tmp4 += s[k];
                }
                else if(cnt>2)
                    return false;
            }
            ++k;
        }
        if(tmp1!="")
            return tmp1==tmp2 && tmp3==tmp4;
        set<char> st;
        for(auto it:s)
            st.insert(it);
        return st.size()<n1;
    }
};