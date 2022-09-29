class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> vec;
        vector<int> v;
        for(int i=0;i<arr.size();i++)
            vec.push_back({x-arr[i],arr[i]});
        sort(vec.begin(),vec.end(),[&](pair<int,int>&a,pair<int,int>&b){
           if(abs(a.first)==abs(b.first))
               return a.second<b.second;
            return abs(a.first)<abs(b.first);
        });
        for(int i=0;i<k;i++)
            v.push_back(vec[i].second);
        sort(v.begin(),v.end());
        return v;
    }
};