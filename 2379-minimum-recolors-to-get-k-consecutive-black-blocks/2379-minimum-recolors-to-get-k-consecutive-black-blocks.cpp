class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.length();
        int i=0,j=0,cnt=0,mini=INT_MAX;
        while(j<n){
            if(blocks[j]=='W'){
                ++cnt;
            }
            if((j-i+1)>k){
                if(blocks[i]=='W')
                    --cnt;
                ++i;
            }
            if((j-i+1)==k){
                mini = min(mini,cnt);
            }
            ++j;
        }
        return mini;
    }
};