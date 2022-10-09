class Solution {
public:
    char fun(vector<int> v){
        for(int i=0;i<26;i++)
            if(v[i])
                return i+'a';
        return 'b';
    }
    string robotWithString(string s) {
        vector<int> v(26);
        for(auto it:s)
            v[it-'a']++;
        string res;
        stack<char> st;
        for(auto it:s){
            st.push(it);
            v[it-'a']--;
            while(!st.empty() && st.top()<=fun(v)){
                res += st.top();
                st.pop();  
            }
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};