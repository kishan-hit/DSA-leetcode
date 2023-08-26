class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int cnt=1;
        vector<int> v = pairs[0];
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]>v[1]){
                ++cnt;
                v = pairs[i];
            }
        }
        return cnt;
    }
};