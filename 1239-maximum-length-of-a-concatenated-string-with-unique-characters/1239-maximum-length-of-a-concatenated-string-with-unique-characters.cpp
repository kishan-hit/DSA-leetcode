class Solution {
public:
    int ans=0;
    bool isunique(string &s){
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a']==1)
                return false;
            v[s[i]-'a']++;
        }
        return true;
    }
    void fun(vector<string>& arr,int idx,string s){
        if(!isunique(s))
            return;
        int temp=s.length();
        ans=max(ans,temp);
        if(idx>=arr.size())
            return;
        fun(arr,idx+1,s+arr[idx]);
        fun(arr,idx+1,s);     
    }
    int maxLength(vector<string>& arr) 
    {
        fun(arr,0,"");
        return ans;  
    }
};