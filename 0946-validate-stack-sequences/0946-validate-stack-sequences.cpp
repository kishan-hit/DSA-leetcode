class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,n=pushed.size();
        stack<int> st;
        for(int j=0;j<n;j++){
            st.push(pushed[j]);
            while(!st.empty() && st.top()==popped[i]){
                ++i;
                st.pop();
            }
        }
        while(i<n){
            if(st.top()==popped[i]){
                ++i;
                st.pop();
            }
            else
                break;
        }
        return st.empty();
    }
};