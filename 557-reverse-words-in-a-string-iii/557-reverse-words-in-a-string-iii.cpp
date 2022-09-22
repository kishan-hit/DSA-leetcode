class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string str;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(st.size()>0){
                    while(!st.empty()){
                        str += st.top();
                        st.pop();
                    }
                    if(str.length()>0)
                        str += ' ';
                }
            }
            else
                st.push(s[i]);
        }
        while(st.size()!=0){
            str += st.top();
            st.pop();
        }
        return str;
    }
};