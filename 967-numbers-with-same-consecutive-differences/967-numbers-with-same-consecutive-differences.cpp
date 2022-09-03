class Solution {
public:
    void fun(vector<int>&v,int n,int k,int num,int ind){
        if(n==0){
            v.push_back(num);
            return;
        }
        for(int i=0;i<10;i++)
            if(abs(i-ind)==k)
                fun(v,n-1,k,num*10+i,i);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> v;
        for(int i=1;i<10;i++)
             fun(v,n-1,k,i,i);
        return v;
    }
};