//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        vector<pair<int,int>> vec;
        for(auto it:mp)
            vec.push_back({it.second,it.first});
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        vector<int> v;
        for(int i=0;i<k;i++)
            v.push_back(vec[i].second);
        return v;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends