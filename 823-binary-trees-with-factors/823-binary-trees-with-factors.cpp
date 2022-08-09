class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mod=1e9+7;
        unordered_map<long long,long long> mp;
        for(auto it:arr)
            mp[it] = 1;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && mp.find(arr[i]/arr[j])!=mp.end()){
                    mp[arr[i]] = (mp[arr[i]]%mod + (mp[arr[j]]%mod*mp[arr[i]/arr[j]]%mod))%mod;
                }
            }
        }
        long long sum = 0;
        for(auto it:mp)
            sum = (sum%mod+it.second%mod)%mod;
        return (int)sum;
    }
};