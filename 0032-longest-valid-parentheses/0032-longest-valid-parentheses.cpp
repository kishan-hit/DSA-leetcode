class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                st.push(i);
            else if(!st.empty()){
                s[st.top()] = s[i] = '*';
                st.pop();
            }
        }
        int cnt=0,maxi=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='*')
                ++cnt;
            else{
                maxi = max(maxi,cnt);
                cnt = 0;
            }
        }
        maxi = max(maxi,cnt);
        return maxi;
    }
};