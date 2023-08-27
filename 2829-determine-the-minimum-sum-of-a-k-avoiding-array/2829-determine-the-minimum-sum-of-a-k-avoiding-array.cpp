class Solution {
public:
    int minimumSum(int n, int k) {
        int val=1,sum=0;
        map<int,int> st;
        while(st.size()!=n){
            if(st.find(k-val)!=st.end()){
                ++val;
                continue;
            }
            st[val]++;
            ++val;
        }
        for(auto it:st)
            sum += it.first;
        return sum;
    }
};