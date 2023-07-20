class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int> st;
        int i=0;
        while(i<n){
            if(st.empty()){
                st.push(a[i]);
                ++i;
            }
            else{
                if((a[i]>0 && st.top()>0) || (a[i]<0 && st.top()<0) || (a[i]>0 && st.top()<0)){
                    st.push(a[i]);
                    ++i;
                }
                else{
                    int temp = st.top();
                    st.pop();
                    if(temp == abs(a[i]))
                        ++i;
                    else if(temp>abs(a[i])){
                        st.push(temp);
                        ++i;
                    }
                }
            }
        }
        vector<int> v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};