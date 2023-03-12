class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int N = asteroids.size();
        stack<int> st;
        int i=0;
        while(i<N){
            if(st.empty()){
                st.push(asteroids[i]);
                ++i;
            }
            else{
                if((asteroids[i]>0&&st.top()>0)||(asteroids[i]<0&&st.top()<0)||(asteroids[i]>0&&st.top()<0)){
                    st.push(asteroids[i]);
                    ++i;
                }
                else{
                    int cur = st.top();
                    st.pop();
                    if(abs(asteroids[i])==cur)
                        ++i;
                    else if(cur>abs(asteroids[i])){
                        st.push(cur);
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