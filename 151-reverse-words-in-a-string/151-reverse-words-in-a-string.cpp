class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string str;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(str.length()>0)
                    st.push(str);
                str = "";
            }
            else
                str += s[i];
        }
        if(str.length()>0)
            st.push(str);
        str = "";
        while(st.size()){
            str += st.top();
            if(st.size()>1)
                str += " ";
            st.pop();
        }
        return str;
    }
};