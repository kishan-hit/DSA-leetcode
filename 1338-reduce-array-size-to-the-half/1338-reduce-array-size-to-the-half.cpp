class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(auto it:arr)
            mp[it]++;
        vector<int> vec;
        for(auto it:mp)
            vec.push_back(it.second);
        sort(vec.begin(),vec.end());
        int sum=0,cnt=0,i;
        for(i=vec.size()-1;i>=0;i--){
            if(sum<n/2){
                sum += vec[i];
                ++cnt;
            }
            else
                break;
        }
        return cnt;
    }
};