class Solution {
public:
    int strStr(string h, string needle) {
        int n=h.length(); 
        int ans=-1; 
        int m=needle.length(); 
        for(int i=0;i<n-m+1;i++){ 
            if(h.substr(i,m)==needle){ 
                ans= i; 
                break; 
            } 
        } 
        return ans; 
    }
};